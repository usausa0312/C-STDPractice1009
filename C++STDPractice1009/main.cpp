#include	"main.h"

int main(void)
{
	//静的
	CRect<int, unsigned int> r(17, 6);
	std::cout << "静的" << std::endl;
	r.Show();
	std::cout<< std::endl;

	//ポインタ
	CRect<float, double>* rp = new CRect<float, double>(0.25f,0.80);
	std::cout << "動的" << std::endl;
	rp->Show();
	delete rp;
	std::cout << std::endl;

	//スマートポインタ
	std::unique_ptr<CRect<uint64_t, uint64_t>>rup = 
		std::make_unique<CRect<uint64_t, uint64_t>>(12,56);
	std::cout << "スマートポインタ" << std::endl;
	rup->Show();
	std::cout << std::endl;
	//解放処理必要なし

	//vector
	std::vector<CRect<float, float>*>vr;
	vr.emplace_back(new CRect <float, float>(12.0f, 5.0f));
	vr.emplace_back(new CRect <float, float>( 2.0f, 3.0f));
	vr.emplace_back(new CRect <float, float>( 8.0f, 3.0f));
	std::cout << "vector" << std::endl;
	for (const auto& v : vr)
	{
		v->Show();
	}
	std::cout << std::endl;
	//unordered_map
	std::unordered_map<std::string, CRect<float, float>*>mr;
	mr["No.0"] = vr[0];
	mr["No.1"] = vr[1];
	mr["No.2"] = vr[2];
	std::cout << "unordered_map" << std::endl;

	mr["No.0"]->Show();
	mr["No.1"]->Show();
	mr["No.2"]->Show();

	for (const auto& v : mr)
	{
		std::cout << v.first << ":";
		v.second->Show();
	}

	//メモリ解放
	for (int i = 0; i < vr.size(); ++i) {
		delete vr[i];
	}

	

	return 1;
}