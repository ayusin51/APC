import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class RankOfNodeInBST {
     private Node root;
        
        private class Node {
            
            private final Integer key;
            private Node right;
            private Node left;
            private int N;
            
            public Node(Integer key) {
                this.key = key;
                N = 1;
            }
        }
        public boolean isEmpty() {
            return size() == 0;
        }
        
        public int size() {
            return sizeOf(root);
        }
        
        private int sizeOf(Node x) {
            return x == null ? 0 : x.N;
        }
    
        public Integer get(int key) {
            Node x = get(root, key);
            return x == null ? null : x.key;
        }
        
        private Node get(Node x, Integer key) {
            if (x == null) {
                return null;
            }
            int cmp = key.compareTo(x.key);
            if (cmp == 0) {
                return x;
            }
            if (cmp < 0) {
                return get(x.left, key);
            }
            return get(x.right, key);
        }
  
  public Node insert(Node root, int key) {
    if(root == null) return new Node(key);
    if(root.key < key) root.right = insert(root.right, key);
    else if(root.key > key) root.left = insert(root.left, key);
    return  root;
  }

public void insert(int key) {
      //complete this function
    if(root == null) root = new Node(key);
    else root = insert(root, key);
	}

    public Integer getRank(Node root, int key, int v) {
      if(root == null) return -1;
      if(root.key == key) return v + sizeOf(root.left);
      if(root.key < key) return getRank(root.right, key, v + sizeOf(root.left) + 1);
      return getRank(root.left, key, v);
    }
    
    public Integer getRank(int key) {
     //complete this function
      if(root == null) return -1;
      return getRank(root, key, -1);
    }
  
  
  public static int getrank(ArrayList<Integer> arr, int k, int s, int e) {
    if(s >= e) return -1;
    int m = (s + e) / 2;
    if(arr.get(m) == k) return m;
    if(arr.get(m) < k) return getrank(arr, k, m + 1, e);
    return getrank(arr, k, s, m - 1);
  }

    
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
      //int[] arr = new int[n];
    Set<Integer> arr = new TreeSet<>();
        for(int i = 0 ; i < n ; i++){
            arr.add(in.nextInt());
        }
      ArrayList<Integer> a = new ArrayList<>(arr);
        int m = in.nextInt();
        for(int i = 0 ; i < m ; i++){
            System.out.println(Collections.binarySearch(a, in.nextInt())); // Change : print -1 if not found
        }
    }
}
