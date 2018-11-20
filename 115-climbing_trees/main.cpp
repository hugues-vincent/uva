#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
typedef struct {
    string parent;
    vector<string> childs;
    int depth;
} node;

int min(int a, int b) {
    return  a < b ? a : b;
}
int main() {
    char child[31], parent[31];
    unordered_map<string, node> tree;
    unordered_set<string> roots;
    queue<node> bfs;

    // build the tree from a.in
    while( scanf("%31s %31s", child, parent) != EOF && (string)child != "no.child" && (string)parent != "no.parent"){ 
        auto child_node = tree.find(child);
        auto parent_node = tree.find(parent);
        if (child_node == tree.end()){
            tree[child] = {parent , {}};
        }
        else {
            roots.erase(child);
            tree[child].parent = parent;
        }
        if (parent_node == tree.end()){
            tree[parent] = {"", {child}};
            roots.insert(parent);
        }
        else {
            tree[parent].childs.push_back(child);
        }
    }
    
    // assign a depth to each node
    for(auto root : roots){ 
        tree[root].depth = 0;
        bfs.push(tree[root]);
    }
    while (!bfs.empty()){
        node curr_node = bfs.front();
        bfs.pop();
        for(string child : curr_node.childs){
            tree[child].depth = curr_node.depth + 1;
            bfs.push(tree[child]);
        }
    }
    
    // print answer to request in a.in 
    while( scanf("%31s %31s", child, parent) != EOF){
        auto lnode = tree.find(child), rnode = tree.find(parent), lnode_tmp = lnode, rnode_tmp = rnode;
        if (lnode == tree.end() || rnode == tree.end()){
            printf("no relation\n");
        }
        else {

            if (lnode->second.depth != rnode->second.depth){
                while(rnode_tmp != tree.end() && rnode_tmp->second.depth > lnode->second.depth){
                    rnode_tmp = tree.find(rnode_tmp->second.parent);
                }
                while(lnode_tmp != tree.end() && lnode_tmp->second.depth > rnode->second.depth){
                    lnode_tmp = tree.find(lnode_tmp->second.parent);
                }
            }
            if( lnode->second.parent == rnode->second.parent){
                printf("sibling\n");
            }
            else if(lnode->first == rnode_tmp->first) {
                int delta = rnode->second.depth - lnode->second.depth;
                for(int i=1; i < delta ; i++){
                    if(i == delta - 1)
                        printf("grand ");
                    else 
                        printf("great ");
                }
                printf("parent\n");
            }
            else if(rnode->first == lnode_tmp->first) {
                int delta = lnode->second.depth - rnode->second.depth;
                for(int i=1; i < delta ; i++) {
                    if(i == delta - 1)
                        printf("grand ");
                    else 
                        printf("great ");
                }
                printf("child\n");
            }
            else {
                while(rnode_tmp != tree.end() && lnode_tmp != tree.end() && rnode_tmp->first != lnode_tmp->first){
                    rnode_tmp = tree.find(rnode_tmp->second.parent);
                    lnode_tmp = tree.find(lnode_tmp->second.parent);
                }
                if(rnode_tmp != tree.end() && lnode_tmp != tree.end()){
                    int n = rnode->second.depth - rnode_tmp->second.depth - 1,
                        m = lnode->second.depth - lnode_tmp->second.depth - 1,
                        k = min(n, m),
                        j = abs(n - m);
                    if (j==0)
                        printf("%d cousin\n", k);
                    else
                        printf("%d cousin removed %d\n", k , j);
                            
                }
                else {
                    printf("no relation\n");

                }
            }
        }
    }
    return 0;
}