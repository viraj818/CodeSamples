#include <stdio.h>
#include <stdlib.h>

struct bstnode {
	struct bstnode* left;
	struct bstnode* right;
	int data;
};


struct bstnode* root = NULL;

void insert(int value){
	struct bstnode* entry = (struct bstnode*)malloc(sizeof(struct bstnode));
	entry->data = value;
	entry->left = NULL;
	entry->right = NULL;
	//If first insertion, make the node the head
	if (root == NULL){
		root = entry;
		return;
	}
	
	//Else, iteratively search through the tree
	struct bstnode* temp = root;
	while (temp != NULL){
		if (temp->data == entry->data){
			return;
		}
		else if (temp->data > entry->data){
			if (temp->left == NULL){
				temp->left = entry;
				return;
			}
			temp = temp->left;
		}
		else{
			if (temp->right == NULL){
				temp->right = entry;
				return;
			}
			temp = temp->right;
		}
	}
}

//Recursive deletion of an element
struct bstnode* delete(struct bstnode* root, int value){
	if (root == NULL){
		return root;
	}

	if (root->data > value){
		root->left = delete(root->left, value);
	}
	else if (root->data < value){
		root->right = delete(root->right, value);
	}
	else {
		if (root->right == NULL){
			struct bstnode* temp = root->left;
			free(root);
			return temp;
		}
		else if (root->left == NULL){
			struct bstnode* temp = root->right;
			free(root);
			return temp;
		}
		else{
			struct bstnode* child = root->right;
			while (child->left != NULL)
				child = child->left;
			root->data = child->data;
			root->right = delete(root->right, child->data);
		}
	}
	return root;
}

//Three different methods of printing out the BST's elements
void preorder(struct bstnode* input){
	if (input == NULL)
		return;
	printf("%d   ", input->data);
	preorder(input->left);
	preorder(input->right);

}

void inorder(struct bstnode* input){
	if (input == NULL)
		return;
	inorder(input->left);
	printf("%d   ", input->data);
	inorder(input->right);

}

void postorder(struct bstnode* input){
	if (input == NULL)
		return;
	postorder(input->left);
	postorder(input->right);
	printf("%d   ", input->data);
}

//Use postorder traversal to free all nodes of tree
void deallocate(struct bstnode* input){
	if (input == NULL)
		return;
	deallocate(input->left);
	deallocate(input->right);
	free(input);
}

int main(){

	insert(50);
	insert(30);
    	insert(40);
    	insert(20);
	insert(70);
    	insert(80);
	insert(60);
	insert(65);
	delete(root, 50);
    	preorder(root);
    	deallocate(root);
	return 0;
}
