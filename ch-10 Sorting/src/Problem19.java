public class Problem19 {
    int data, count;
    Problem19 left,right;

    static Problem19 createBST (Problem19 root, int data) {
        if (root == null) {
            root = new Problem19();
            root.data = data;
            root.count = 1;
            root.left = null;
            root.right = null;
        } else if (data < root.data) {
            root.left = createBST(root.left, data);
        } else if (data == root.data) {
            root.count++;
        } else {
            root.right = createBST(root.right,data);
        }
        return root;
    }
    static void preOrder (Problem19 root) {
        if (root != null) {
            System.out.print(root.data + " ");
            preOrder(root.left);
            preOrder(root.right);
        }

    }
    static void inOrder (Problem19 root, Problem19 max) {
        if (root != null) {
            inOrder(root.left, max);
            if (root.count > max.count) {
                max.count = root.count;
                max.data = root.data;
            }
            inOrder(root.right,max);
        }
    }
    public static void main (String args[]) {
        int a[]={6,5,4,3,2,1,4,7,3,2,8,1,5,5,5,5,5};
        Problem19 root = null;
        Problem19 maxNode = new Problem19();
        maxNode.count = 0;
        for (int num : a) {
            root = createBST(root, num);
        }
        System.out.println("Preorder traversal of BST:");
        preOrder(root);
        //System.out.println("Inorder traversal of BST:");
        inOrder(root, maxNode);
        System.out.println("Maximum time occurring number:"+maxNode.data);
    }
}
