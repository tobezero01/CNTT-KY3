#include <iostream>
using namespace std;

struct node {
	int key;
	struct node *left;
	struct node *right;
};

/* Hàm tìm kiếm một phần tử trong cây BST */
struct node* search(struct node* root, int key)
{
    /* Base Cases: Node gốc là NULL hoặc giá trị của node gốc bằng với key */
    if (root == NULL || root->key == key)
       return root;
   
    /* Nếu giá trị cần tìm lớn hơn giá trị của node gốc
        Ta gọi đệ quy hàm tìm kiếm cho nhánh phải của node gốc */
    if (root->key < key)
       return search(root->right, key);

    /* Nếu giá trị cần tìm nhỏ hơn giá trị của node gốc
        Ta gọi đệ quy hàm tìm kiếm cho nhánh trái của node gốc */
    return search(root->left, key);
}

/* Hàm tiện ích giúp tạo BST node */
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* Hàm chèn một phần tử mới vào cây BST */
struct node* Insert(struct node* node, int key)
{
    /* Nếu cây là rỗng, trả về một node mới */
    if (node == NULL) return newNode(key);
 
    /* Ngược lại, gọi đệ quy tới các con trong cây */
    if (key < node->key)
        node->left  = Insert(node->left, key);
    else if (key > node->key)
        node->right = Insert(node->right, key);   
 
    return node;
}

/* Hàm tìm giá trị lớn nhất trong cây */ 
node* FindMax(node* root)
{
	while(root->right != NULL) root = root->right;
	return root;
}

/* Hàm xóa một node khỏi BST */
struct node* Delete(struct node *root, int key) {
	if(root == NULL) return root; 
	else if(key < root->key) root->left = Delete(root->left,key);
	else if (key > root->key) root->right = Delete(root->right,key);
	else {
		/* Case 1:  Node lá, không có con */
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		/* Case 2: Có một con  */
		else if(root->left == NULL) {
			struct node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct node *temp = root;
			root = root->left;
			delete temp;
		}
		/* case 3: Có hai con */
		else { 
			struct node *temp = FindMax(root->left);
			root->key = temp->key;
			root->left = Delete(root->left,temp->key);
		}
	}
	return root;
}

/* hàm duyệt cây theo thứu tự Inorder */
void Inorder(struct node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       /* Duyệt cây con bên trái */
	printf("%d ",root->key);   /* In ra key */
	Inorder(root->right);      /* Duyệt cây con bên phải */
}

/* Hàm in ra tất cả các node theo thứ tự Inorder */
void printBST(struct node *root){
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
}
int main()
{
	/*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
    struct node* root = NULL;
    
    root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);
	/* In ra tất cả các node theo thứ tự Inorder */
	printBST(root);
	
	root = Delete(root,5);
	/* In ra tất cả các node theo thứ tự Inorder */
	printBST(root);

    return 0;
}