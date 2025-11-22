#include <iostream>
#include <string>
#include <ctime>
#include <vector>

int totaltrans = 0;
int totalcash = 0;

class Audit{
	protected:
		std::string currenttime, transactiontype, transactiondetails;
		int cashflow;
	public:
		std::string formatCash(std::string cash, std::string type){
			std::string formatted;
			if (type == "Out"){
				formatted += "- Rp. ";
			}else if (type == "In"){
				formatted += "+ Rp. ";
			}else{
				formatted += "Rp. ";
			}
			int length = cash.length();
			int counter = 3-length%3;
			if (counter >= 3){
				counter = 0;
			}
			for (int x = 0; x<length; x++){
				formatted += cash[x];
				if (counter == 2){
					formatted += ".";
					counter == 0;
				}
				counter++;
			}
			formatted += ".00";
			return formatted;
		}
		Audit(){
			time_t ct = time(0);
			currenttime = (ctime(&ct));
		}
		
		std::string getTime(){
			return "Tanggal Transaksi : " + currenttime;
		}
		
		std::string getDetails(){
			return transactiontype + " / " + transactiondetails;
		}
};

class Debit : public Audit{
	private:
		std::string cardnumber, bank, securitycode, finished;
	public:
		Debit(std::string num, std::string bank, std::string code, int cash, std::string type, std::string details) : Audit(){
			cardnumber = num;
			this -> bank = bank;
			securitycode = code;
			cashflow = cash;
			transactiontype = type;
			transactiondetails = details;
		}
		
		std::string getLog(){
			finished = "Debit / " + cardnumber + "-" + securitycode + " / " + bank + " / " + formatCash(std::to_string(cashflow), transactiontype) + " / " + getDetails() + " / " + currenttime;
			return finished;
		}
};

class Qris : public Audit{
	private:
		std::string qriscode, bank, accountnumber, finished;
	public:
		Qris(std::string qris, std::string bank, std::string account, int cash, std::string type, std::string details) : Audit(){
			qriscode = qris;
			this -> bank = bank;
			accountnumber = account;
			cashflow = cash;
			transactiontype = type;
			transactiondetails = details;
		}
		
		std::string getLogs(){
			finished = "QRIS / " + qriscode + " / " + accountnumber + " / " + bank + " / " + formatCash(std::to_string(cashflow), transactiontype) + " / " + getDetails() + " / " + currenttime;
			return finished;
		}
};

class Transaction : public Audit{
	protected:
		int transactionmethod;
		double final, discount;
	public:
		std::string addTransaction(){
			std::cout<<"Metode Pembayaran:\n1. Debit\n2. QRIS\n3. Cash\n";
			std::cin>>transactionmethod;
			std::cout<<"Jumlah yang dibayar : ";
			std::cin>>cashflow;
			if (transactiontype == "Out"){
				totalcash -= cashflow;
			}else{
				totalcash += cashflow;
			}
			switch (transactionmethod){
				case 1:{
					std::string a, b, c;
					std::cout<<"Masukkan ID Kartu Pembayar (16 digit) : ";
					std::cin>>a;
					std::cout<<"Masukkan Nama Bank Penyedia : ";
					std::cin>>b;
					std::cout<<"Masukkan Kode Sekuritas (3 digit di belakang kartu) : ";
					std::cin>>c;
					Debit* newtrans = new Debit(a,b,c,cashflow,transactiontype,transactiondetails);
					return newtrans -> getLog();
					break;
				}
				case 2:{
					std::string a, b, c;
					std::cout<<"Masukkan kode QRIS dari QR-Code : ";
					std::cin>>a;
					std::cout<<"Masukkan Nama Bank Penyedia : ";
					std::cin>>b;
					std::cout<<"Masukkan Nomor Akun Pembayar : ";
					std::cin>>c;
					Qris* newtrans = new Qris(a,b,c,cashflow,transactiontype,transactiondetails);
					return newtrans -> getLogs();
					break;
				}
				default:{
					return "Cash / ----- / ----- / " + formatCash(std::to_string(cashflow), transactiontype) + " / " + getDetails() + " / " + currenttime;
					break;
				}
			}
		}
		
		Transaction(): Audit(){}
		Transaction(std::string type, std::string details) : Audit(){
			transactiontype = type;
			transactiondetails = details;
		}
};

class Logger : public Transaction{
	private:
		std::vector<std::string> translog = {};
		int findsize;
	public:
		Logger() : Transaction(){}
		
		void updateTransList(std::string adder){
			translog.push_back(adder);
			findsize = translog.size();
			std::cout<<translog[totaltrans];
			totaltrans++;
		};
		
		void getTransList(){
			findsize = translog.size();
			std::cout<<"\n----------------------------------TRANSAKSI SELAMA INI----------------------------------\n\n";
			for (int i = 0; i <findsize; i++){
				std::cout<<translog[i];
			}
			std::cout<<"\nKas tersedia sekarang : "<<formatCash(std::to_string(totalcash), "null")<<"\n";
		}
};

int main()
{
	Logger auditlog;
	int choice, amt;
	std::string desc, type;
	while(true){
		std::cout<<"\n\nTambahkan transaksi?\n1. Ya\n2. Tidak\n3. Tampilkan semua transaksi\n";
		std::cin>>choice;
		if (choice == 1){
			std::cout<<"Deskripsi transaksi : ";
			std::cin.ignore();
			std::getline(std::cin,desc);
			std::cout<<"Tipe transaksi?\n1. Masuk\n2. Keluar\n";
			std::cin>>choice;
			if (choice == 1){
				type = "In";
			}else{
				type = "Out";
			}
			Transaction* x1 = new Transaction(type, desc);
			auditlog.updateTransList(x1->addTransaction());
			delete x1;
		}else if(choice == 3){
			auditlog.getTransList();
			continue;
		}else{
			break;
		}
	}
	return 0;
}
