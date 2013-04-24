

void getGraph(ifstream &in_file){
	
	vector <int> site_names;
	int new_site;
	in_file >> new_site;
	
	site_names.append(new_site);

	
	int site_nb=site_names.size();
	for(int i=0; i<site_nb;i++){
		sites.emplace_back(site_names[i]);
	}

}
