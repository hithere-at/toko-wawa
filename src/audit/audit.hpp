#include <string>
#include <vector>

int totaltrans = 0;
int totalcash = 0;

class Audit{

    protected:
        std::string currenttime, transactiontype, transactiondetails;
        int cashflow;

    public:
        Audit();
        std::string formatCash(std::string cash, std::string type);
        std::string getTime();
        std::string getDetails();

};

class Debit : public Audit{

    private:
        std::string cardnumber, bank, securitycode, finished;

    public:
        Debit(std::string num, std::string bank, std::string code, int cash, std::string type, std::string details);
        std::string getLog();

};

class Qris : public Audit{

    private:
        std::string qriscode, bank, accountnumber, finished;

    public:
        Qris(std::string qris, std::string bank, std::string account, int cash, std::string type, std::string details);
        std::string getLogs();

};

class Transaction : public Audit{

    protected:
        int transactionmethod;
        double final, discount;

    public:
        Transaction();
        Transaction(std::string type, std::string details);
        std::string addTransaction();

};

class Logger : public Transaction{

	private:
		std::vector<std::string> translog = {};
		int findsize;

	public:
		Logger();
		void updateTransList(std::string adder);
		void getTransList();

};
