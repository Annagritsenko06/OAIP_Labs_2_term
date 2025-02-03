#include <iostream>
#include <fstream>
#include <string>
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

//void insert(TreeNode*& root, int key) {
//    if (!root) {
//        root = new TreeNode(key);
//    }
//    else if (key < root->key) {
//        insert(root->left, key);
//    }
//    else {
//        insert(root->right, key);
//    }
//}
void insert(TreeNode*& root, int key) {
    if (!root) {
        root = new TreeNode(key);
    }
    else if (key < root->key) {
        insert(root->left, key);
    }
    else if (key > root->key) {
        insert(root->right, key);
    }
    else {
        // Ключ уже существует в дереве
        // В данном примере просто игнорируем повторяющиеся ключи
        // Для другого поведения, например, сложения значений,
        // или замены узла с таким ключом, нужно изменить эту часть кода
        return;
    }
}

TreeNode* search(TreeNode* root, int key) {
    if (!root || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorderTraversal(TreeNode* root, std::ofstream& outFile) {
    if (root) {
        inorderTraversal(root->left, outFile);
        outFile << root->key << std::endl;
        inorderTraversal(root->right, outFile);
    }
}

void buildBSTFromFile(TreeNode*& root, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    int num;
    while (file >> num) {
        insert(root, num);
    }

    file.close();
}

void writeBSTToFile(TreeNode* root, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
        return;
    }

    inorderTraversal(root, outFile);

    outFile.close();
}

void view(TreeNode* root, int level) {
    if (root) {
        view(root->right, level + 1);
        for (int i = 0; i < level; i++) {
            std::cout << " ";
        }
        std::cout << root->key << std::endl;
        view(root->left, level + 1);
    }
}
#include <iomanip>



void delAll(TreeNode* root) {
    if (root) {
        delAll(root->left);
        delAll(root->right);
        delete root;
    }
}

//void printFileContent(const std::string& filename) {
//    std::ifstream file(filename);
//    if (!file.is_open()) {
//        std::cerr << "Unable to open file: " << filename << std::endl;
//        return;
//    }
//
//    std::string line;
//    std::cout << "Содержимое файла " << filename << ":\n";
//    while (std::getline(file, line)) {
//        std::cout << line << std::endl;
//    }
//
//    file.close();
//}

int main() {
    setlocale(LC_CTYPE,"rus");
    TreeNode* root = nullptr;
    int choice, key;
    std::string filename;

    for (;;) {
      
        std::cout << "\n1 - Добавление элемента\n";
        std::cout << "2 - Поиск по ключу\n";
        std::cout << "3 - Удаление элемента\n";
        std::cout << "4 - Вывод дерева\n";
        std::cout << "5 - Очистка дерева\n";
        std::cout << "6 - Построение дерева из файла и запись в файл\n";
        std::cout << "7 - запись дерева в файл\n";
        std::cout << "8 - вывод дерева из файл\n";
        std::cout << "9 - Выход\n";
        std::cout << "Ваш выбор? \n";
        std::cin >> choice;

        switch (choice) {
       
        case 1:
            std::cout << "Введите ключ: ";
            std::cin >> key;
            insert(root, key);
            break;
        case 2:
            std::cout << "Введите ключ для поиска: ";
            std::cin >> key;
            if (search(root, key)) {
                std::cout << "Элемент найден\n";
            }
            else {
                std::cout << "Элемент не найден\n";
            }
            break;
        case 3:
            std::cout << "Введите ключ для удаления: ";
            std::cin >> key;
            root = deleteNode(root, key);
            break;
        case 4:
            std::cout << "Дерево:\n";
            view(root, 0);
            break;
        case 5:
            delAll(root);
            root = nullptr;
            std::cout << "Дерево очищено\n";
            break;
        case 6:
            std::cout << "Введите имя файла: ";
            std::cin >> filename;
            buildBSTFromFile(root, filename);
            std::cout << "Дерево построено из файла\n";
            writeBSTToFile(root, "output.txt");
            std::cout << "Элементы дерева записаны в файл output.txt\n";
            break;
        case 7:
            writeBSTToFile(root, "output.txt");
            std::cout << "Элементы дерева записаны в файл output.txt\n";
            break;
        case 8:
            std::cout << "Элементы дерева выведены из файла output.txt\n";
            buildBSTFromFile(root, "output.txt");
            view(root, 0);
            break;
        case 9:
            delAll(root);
            return 0;
        default:
            std::cout << "Неверный выбор\n";
        }
    }
}
