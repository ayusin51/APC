import java.util.Stack;

public class PostfixToInfix {

    static String convert(String prefix) {

        Stack<String> s = new Stack<>();

        int size = prefix.length();
        int i;

        for(i = 0; i < size; i++) {

            char ch = prefix.charAt(i);
            if(Character.isLetter(ch)) {

                s.push(Character.toString(ch));
            }else {

                String str1 = s.peek();
                s.pop();
                String str2 = s.peek();
                s.pop();

                s.push(str2 + ch + str1);
            }
        }

        return s.peek();
    } 

    public static void main(String[] args) {

        String postfix = new String("ab*cd/+");
        System.out.println(convert(postfix));
    }
}
