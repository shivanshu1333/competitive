int main(){
	cin >> s;
	if (s[0] == 'h'){
		ans += "http://";
		index = 4;
	}
	else{
		ans += "ftp://";
		index = 3;
	}
	for (int i = (int)s.size()-3 ; i >= index ; i--)
		if (s[i] == 'r' && s[i+1] == 'u'){
			cout << ans + s.substr(index, i-index) + ".ru/" + s.substr(i+2) << endl;
			return 0;
		}
	cout << ans + s.substr(index, (int)s.size()-2-index) + ".ru" << endl;
	return 0;
}