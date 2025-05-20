import java.util.*;

public class BottomViewOfTree{
    class Node{
        int data;
        Node left, right;
        Node(int d){
            this.data=d;
            this.left=null;
            this.right=null;
        }
    }
    class BinaryTree{
        public Node root;

        public BinaryTree() {
            this.root=null;
        }
        
        Node CreateBT(Scanner cin){
            int d = cin.nextInt();

            if(d == -1)return null;

            Node root = new Node(d);
            root.left = CreateBT(cin);
            root.right= CreateBT(cin);
            return root;
        }
        
        void createBinaryTree(){
            Scanner cin = new Scanner(System.in);
            this.root = CreateBT(cin);
        }

        void preOrderTraversal(Node root, Map<Integer,Node> mp, int hd){
            if(root==null)return;
        }

        void PrintBottomViewOfTree(){
            Map<Integer,Node> mp = new TreeMap<>();

            preOrderTraversal(root, mp, 0);

            List<Integer> ans = new ArrayList<>();
            for(Map.Entry<Integer,Node> it : mp.entrySet()){
                ans.add(it.getValue().data);
            }

            for(Integer it: ans)System.out.println(it);

        }

    }

    public static void main(String args[]){
        BottomViewOfTree classobj = new BottomViewOfTree();

        BinaryTree BT = classobj.new BinaryTree();
        BT.createBinaryTree();
        BT.PrintBottomViewOfTree();

    }
}