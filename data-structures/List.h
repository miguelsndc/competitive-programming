#ifndef LIST_BASE_CLASS
#define LIST_BASE_CLASS
#endif

template <typename E> class List {
private:
    void operator = (const List&) {}
    List(const List&);
public:
    List() {}
    virtual ~List() {}

    // Clear contents from the list, to make it empty
    virtual void clear() = 0;

    // Insert an element at the current position
    // item: The element to be inserted;
    virtual void insert(const E& item) = 0;

    // Append an element to the end of the lsit
    // item: the element to me appended
    virtual void append(const E& item) = 0;

    // Remove and return the current element
    // Return: the element that was removed
    virtual E remove() = 0;

    // Set the current position to the start of the list
    virtual void moveToStart() = 0;

    // Set the current position to the end of the list
    virtual void moveToEnd() = 0;

    // Move the current position one step left. No change if already at beginning.
    virtual void prev() = 0;

    // Move the current position one step right. No change if already at end.
    virtual void next() = 0;

    // Return: the number of elements in the list;
    virtual int length() const = 0;

    // Return: the position of the current element in the list;
    virtual int currPos() const = 0;

    // Set the current position.
    // pos: The position to make current.
    virtual void moveToPos(int pos) = 0;

    virtual const E& getValue() const = 0;
};


















