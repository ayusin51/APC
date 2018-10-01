package queues;

public interface QueueInterface {

    void enque(int a);
    int deque();
    int top();
    int size();
    boolean isEmpty();
}
