export class RBNode {
    constructor(data = null, color = 0, parent = null){
        this.data = data;
        this.left = null;
        this.right = null;
        this.color = color;
        this.parent = parent;
    }
}

export class RedBlackBST {
    constructor(data = null, color = 0, parent = null){
        this.root = new RBNode(data, color, parent);
    }
    insert(value){
        this.root = this.RecursiveInsert(value, this.root);
        this.root.color = 0;
    }
    RecursiveInsert(value, root){
        if (root == null) {
            return new RBNode(value, 1, null);
        }
        if (value < root.data) {
            root.left = this.RecursiveInsert(value, root.left);
            root.left.parent = root;
        } else if (value > root.data) {
            root.right = this.RecursiveInsert(value, root.right);
            root.right.parent = root;
        }
        return root;
    }
    remove(value){
        this.root = this.RecursiveRemove(value, this.root);
        this.root.color = 0;
    }
    RecursiveRemove(value, root) {
        if (root == null) {
            return root;
        }
        if (root.data == value) {
            if (root.left == null && root.right == null) {
                return null;
            }
            if (root.left == null) {
                //root.right.parent = root.parent;
                return root.right;
            }
            if (root.right == null) {
                //root.left.parent = root.parent;
                return root.left;
            }
            var temp = root.left;
            while (temp.right != null) {
                temp = temp.right;
            }
            root.data = temp.data;
            root.left = this.RecursiveRemove(temp.data, root.left);
            return root;
        }
        if (value < root.data) {
            root.left = this.RecursiveRemove(value, root.left);
        } else {
            root.right = this.RecursiveRemove(value, root.right);
        }
        return root;
    }
    search(value){
        return this.RecursiveSearch(value, this.root);
    }
    RecursiveSearch(value, root){
        if (root == null) {
            return root;
        }
        if (value < root.data) {
            return this.RecursiveSearch(value, root.left);
        } else if (value > root.data) {
            return this.RecursiveSearch(value, root.right);
        } else {
            return root;
        }
    }
    print(){
        this.PreOrderPrint(this.root);
    }
    PreOrderPrint(root){
        if (root == null) {
            return;
        }
        if (root.left && root.right) {
            console.log("root: " + root.data + ",left: " + root.left.data + ",right: " + root.right.data);
        } else if (root.left) {
            console.log("root: " + root.data + ",left: " + root.left.data + ",right: null");
        } else if (root.right) {
            console.log("root: " + root.data + ",left: null, right: " + root.right.data);
        } else {
            console.log("root: " + root.data + ",left: null, right: null");
        }
        this.PreOrderPrint(root.left);
        this.PreOrderPrint(root.right);
    }
    rotateLeft(root){
        if (root == null || root.right == null) {
            return root;
        }
        var temp = root.right;
        root.right = temp.left;
        if (temp.left != null) {
            temp.left.parent = root;
        }
        temp.parent = root.parent;
        if (root.parent == null) {
            this.root = temp;
        } else if (root.parent.left == root) {
            root.parent.left = temp;
        } else {
            root.parent.right = temp;
        }
        temp.left = root;
        root.parent = temp;
        return temp;
    }
    rotateRight(root){
        if (root == null || root.left == null) {
            return root;
        }
        var temp = root.left;
        root.left = temp.right;
        if (temp.right != null) {
            temp.right.parent = root;
        }
        temp.parent = root.parent;
        if (root.parent == null) {
            this.root = temp;
        } else if (root.parent.right == root) {
            root.parent.right = temp;
        } else {
            root.parent.left = temp;
        }
        temp.right = root;
        root.parent = temp;
        return temp;
    }
    isRed(root){
        if (root == null) {
            return false;
        }
        return root.color == 1;
    }
    flipColors(root){
        root.color = 1;
        root.left.color = 0;
        root.right.color = 0;
    }
}