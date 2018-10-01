package queues;

public class PriorityQueue {

    private int []arr;
    private int size;
    private int end;
    private int capacity;


    public PriorityQueue() {

        this(100);
    }

    public PriorityQueue(int n) {

        arr = new int[2 * n];
        size = 0;
        end = -1;
        capacity = 2 * n;

    }

    int max(int a, int b) {

        return arr[a] > arr[b] ? a : b;
    }

    private int swap(int a, int b) {

        return a;
    }

    private void printArray() {

        for(int i = 0; i <= end; i++) System.out.print(" " + arr[i]);
        System.out.println();
    }

    private void swim() {

        int p = end / 2;
        int curr = end;
        while((p >= 0) && (arr[curr] > arr[p])) {

//            int a = arr[curr], b = arr[p];
            arr[p] = swap(arr[curr], arr[curr] = arr[p]);
//            System.out.println("Swapping " + curr + "And " + p);
//            if(!(a == arr[p] && b == arr[curr])) System.out.println("Fineeee");
            curr = p;
            p = curr / 2;
        }
    }

    private void sink() {

        int curr = 0;
        int left = 2 * curr + 1;
        int right = left + 1;
        while(true) { // && (arr[curr] < arr[left] || arr[curr] < arr[right])) {

            int m;
            if(left > end && right > end ) return;
            if(left <= end && right <= end)
                m = max(left, right);
            else if(left > end)
                m = right;
            else
                m = left;

//            if(size == 2) System.out.println("curr = " + curr + " val = " + arr[curr] + " m = " + m + " val = " + arr[m] + " left : " + left + " right : " + right);
            if(arr[curr] < arr[m]) {
                arr[m] = swap(arr[curr], arr[curr] = arr[m]);
                curr = m;
                left = 2 * curr;
                right = left + 1;
            } else return;
        }
    }


//    private void sink() 

    public void insert(int n) {

        if(size < capacity) {
            arr[++end] = n;
            size++;
            swim();
//            printArray();
        }else
            System.out.println("Queue Overflow");
    }

    public void deque() {

        if(size <= 0) return;

        arr[end] = swap(arr[0], arr[0] = arr[end]);
        end--;
        size--;
        sink();
//        size--;
//        printArray();
    }

    public int peek() {

        if(size > 0) return arr[0];

        return -999999999;
    }

    
    public static void main(String[] args) {

        PriorityQueue pq = new PriorityQueue();
        pq.insert(8);
        pq.insert(7);
        pq.insert(16);
        pq.insert(2);
        pq.insert(43);
        pq.insert(19);
        pq.insert(10);

        System.out.println("Final Array :");
        pq.printArray();

        while(pq.peek() != -999999999) {

            System.out.println(pq.peek());
            pq.deque();
        }

    }

}
