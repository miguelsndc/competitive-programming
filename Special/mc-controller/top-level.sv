module microwave_controller (
    input wire clk,
    input wire rst,           // Reset signal
    input wire [9:0] keypad,  // Keypad inputs
    input wire start_stop,    // Start/Stop button
    input wire door_sensor,   // Door sensor input
    output wire [6:0] display, // 7-segment display output
    output wire mag_control,  // Microwave power control
    output wire buzzer        // Buzzer for alerts
);

    // Internal signals
    wire [3:0] time_minutes;
    wire [3:0] time_seconds;
    wire [2:0] power_level;
    wire cooking;

    // Instantiate the keypad interface
    keypad_interface kp (
        .clk(clk),
        .rst(rst),
        .keypad(keypad),
        .time_minutes(time_minutes),
        .time_seconds(time_seconds),
        .power_level(power_level)
    );

    // Instantiate the display controller
    display_controller dc (
        .clk(clk),
        .time_minutes(time_minutes),
        .time_seconds(time_seconds),
        .display(display)
    );

    // Instantiate the cooking state machine
    cooking_fsm fsm (
        .clk(clk),
        .rst(rst),
        .start_stop(start_stop),
        .door_sensor(door_sensor),
        .time_minutes(time_minutes),
        .time_seconds(time_seconds),
        .power_level(power_level),
        .cooking(cooking),
        .mag_control(mag_control),
        .buzzer(buzzer)
    );

endmodule
