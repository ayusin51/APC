import java.util.Stack;

public class InfixToPostfix {

    static int precision(char ch) {

        if(ch == '+' || ch == '-') return 1;
        if(ch == '*' || ch == '/' || ch == '%') return 2;
        return 0;
    }

    static String convert(String infix) {

        Stack<Character> s = new Stack<>();
        int i = 0;
        int size = infix.length();
        String postfix = new String();

        for(i = 0; i < size; i++) {

            char ch = infix.charAt(i);
            if(Character.isLetter(ch)) postfix += ch;
            else {

                if(ch == ')') {

                    while(!s.empty() && s.peek() != '(') {

                        postfix += s.peek();
                        s.pop();
                    }
                    s.pop();
                   
                } else if(ch == '(') s.push(ch);
                else {
                    while(!s.empty() && precision(s.peek()) >= precision(ch) && s.peek() != '(') {

                        postfix += s.peek();
                        s.pop();
                    }

                    s.push(ch);
                }
            } 
        }

        while(!s.empty()) {

            if(s.peek() != '(' && s.peek() != ')') postfix += s.peek();
            s.pop();
        }

        return postfix;
    }


    public static void main(String[] args) {

        String str = new String("(a*b)+(c*d*e)+j");
        System.out.println(convert(str));
    }
}
