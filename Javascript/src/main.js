import './RB-BST.js';
import { RBNode, RedBlackBST } from './RB-BST.js';

let tree = new RedBlackBST(10);

tree.insert(12);
tree.insert(13);
tree.insert(11);

tree.rotateLeft(tree.root);

tree.print();