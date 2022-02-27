void printBottom(Node *node, int dist, int level, auto &map){
	if (node == nullptr)
		return;
	if (level >= map[dist].second)
		map[dist] = { node->key, level };
	printBottom(node->left, dist - 1, level + 1, map);
	printBottom(node->right, dist + 1, level + 1, map);
}
void printBottom(Node *root){
	map<int, pair<int, int>> map;
	printBottom(root, 0, 0, map);
	for (auto it: map)
		cout << it.second.first << " ";
}
//top
void printTop(Node *root, int dist, int level, auto &map){
    if (root == nullptr)
        return;
    if (map.find(dist) == map.end() || level < map[dist].second)
        map[dist] = { root->key, level };
    printTop(root->left, dist - 1, level + 1, map);
    printTop(root->right, dist + 1, level + 1, map);
}
void printTop(Node *root){
    map<int, pair<int, int>> map;
    printTop(root, 0, 0, map);
     for (auto it: map)
        cout << it.second.first << " ";
}