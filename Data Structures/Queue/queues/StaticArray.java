package queues;

public class StaticArray implements QueueInterface {

    int arr[];
    int head;
    int tail;
    int size;
    int capacity;

    public StaticArray() {

        this(5);
    }

    public StaticArray(int c) {

        arr = new int[c];
        head = 0;
        tail = -1;
        size = 0;
        capacity = c;
    }

//    @override
    public void enque(int d) {

        if(isFull()) {

            System.out.println("Queue Overflow...");
        }else {

            tail = (tail + 1) % capacity;
            arr[tail] = d;
            size++;
        }
    }

//    @override
    public int deque() {

        if(isEmpty()) {

            System.out.println("Queue Underflow...");
            return -999999999;
        }

        int d = arr[head];
        head = (1 + head) % capacity;
        size--;
        return d;
    }

//    @override
    public int top() {

        if(!isEmpty()) return arr[head];
        return -999999999;
    }

//    @override
    public int size() {

        return size;
    }

//    @override
    public boolean isEmpty() {

        return (size == 0);
    }

    private boolean isFull() {

        return (size == capacity);
    }


    public static void main(String[] args) {

        QueueInterface q = new StaticArray();

        for(int i = 0; i < 10; i++) {

            q.enque(i);
        }
        
        for(int i = 0; i < 12; i++) {

            System.out.println(q.deque());
        }
    }
}
