module cooking_fsm (
    input wire clk,
    input wire rst,
    input wire start_stop,
    input wire door_sensor,
    input wire [3:0] time_minutes,
    input wire [3:0] time_seconds,
    input wire [2:0] power_level,
    output reg cooking,
    output reg mag_control,
    output reg buzzer
);
    // State encoding
    typedef enum reg [1:0] {
        IDLE,
        COOKING,
        PAUSED,
        DONE
    } state_t;

    state_t state, next_state;

    // Timer registers
    reg [3:0] timer_minutes;
    reg [3:0] timer_seconds;

    // State transition logic
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;
            timer_minutes <= 4'd0;
            timer_seconds <= 4'd0;
        end else begin
            state <= next_state;
            if (state == COOKING) begin
                // Decrement timer logic
                if (timer_seconds == 4'd0) begin
                    if (timer_minutes > 4'd0) begin
                        timer_minutes <= timer_minutes - 4'd1;
                        timer_seconds <= 4'd9;
                    end else begin
                        next_state <= DONE;
                    end
                end else begin
                    timer_seconds <= timer_seconds - 4'd1;
                end
            end
        end
    end

    // Next state and output logic
    always @* begin
        next_state = state;
        cooking = 1'b0;
        mag_control = 1'b0;
        buzzer = 1'b0;

        case (state)
            IDLE: begin
                if (start_stop && !door_sensor) begin
                    next_state = COOKING;
                    timer_minutes = time_minutes;
                    timer_seconds = time_seconds;
                end
            end
            COOKING: begin
                cooking = 1'b1;
                mag_control = (power_level > 3'd0);
                if (start_stop || door_sensor) begin
                    next_state = PAUSED;
                end else if (timer_minutes == 4'd0 && timer_seconds == 4'd0) begin
                    next_state = DONE;
                end
            end
            PAUSED: begin
                if (!start_stop && !door_sensor) begin
                    next_state = COOKING;
                end
            end
            DONE: begin
                buzzer = 1'b1;
                if (start_stop) begin
                    next_state = IDLE;
                end
            end
        endcase
    end

endmodule
