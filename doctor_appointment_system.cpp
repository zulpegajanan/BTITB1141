#include <iostream>
#include <vector>
using namespace std;

class Doctor {
public:
    int id;
    string name;
    string contact_no;
    string role;

    Doctor(int a, string b, string c, string d) {
        id = a;
        name = b;
        contact_no = c;
        role = d;
    }

    void showDoctorInfo() {
        cout << "--------------\nDoctor Information:\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Contact Number: " << contact_no << endl;
        cout << "Role: " << role << endl;
    }
};

class Patient {
public:
    int id;
    string name;
    string contact_no;
    string type;

    Patient(int a, string b, string c, string d) {
        id = a;
        name = b;
        contact_no = c;
        type = d;
    }

    void showPatientInfo() {
        cout << "--------------\nPatient Information:\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Contact Number: " << contact_no << endl;
        cout << "Type: " << type << endl;
    }
};

class Nurse {
public:
    int id;
    string name;
    string contact_no;
    string specialty;

    Nurse(int a, string b, string c, string d) {
        id = a;
        name = b;
        contact_no = c;
        specialty = d;
    }

    void showNurseInfo() {
        cout << "--------------\nNurse Information:\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Contact Number: " << contact_no << endl;
        cout << "Specialty: " << specialty << endl;
    }
};


void getAllDoctors(const vector<Doctor>& DoctVect) {
    cout << "------------\nid \t name \t\t contact_no \t\t role \n";
    for (const Doctor& it : DoctVect) {
        cout << it.id << "\t" << it.name << "\t" << it.contact_no << "\t" << it.role << endl;
    }
}

void getAllPatients(const vector<Patient>& PatVect) {
    cout << "------------\nid \t name \t\t contact_no \t\t type \n";
    for (const Patient& it : PatVect) {
        cout << it.id << "\t" << it.name << "\t" << it.contact_no << "\t" << it.type << endl;
    }
}

void getAllNurces(const vector<Nurse>& NurVect) {
    cout << "------------\nid \t name \t\t contact_no \t\t type \n";
    for (const Nurse& it : NurVect) {
        cout << it.id << "\t" << it.name << "\t" << it.contact_no << "\t" << it.specialty << endl;
    }
}


class Payment {
protected:
    int amount;
    string date;
    string mode;

public:
    Payment(int amt, const string& dt, const string& md)
        : amount(amt), date(dt), mode(md) {}

    void displayPaymentInfo() {
        cout << "Amount: " << amount << "\nDate: " << date << "\nPayment Mode: " << mode;
    }
};


class Entry {
protected:
    int id;
    Doctor d;
    Patient p;
    Nurse n;
    Payment pay;
    
    

public:
    Entry(int aa, Doctor bb, Patient cc, Nurse dd, Payment ee)
    : id(aa), d(bb), p(cc), n(dd), pay(ee) {}

 

    void displayEntryInfo() {
	    cout << "-----------------------------" << endl;
	    d.showDoctorInfo();
	    p.showPatientInfo();
	    n.showNurseInfo();
	    pay.displayPaymentInfo();
	}

};

int main() {
    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<Nurse> nurses;
    vector<Entry> Record;

    int mainID = 1;

    while (true) {
        // Patient info
        cout << "Enter Patient Info:\n";
        int patient_id;
        string patient_name;
        string patient_Cno;
        string patient_problem;

        cout << "\t Enter id: ";
        cin >> patient_id;
        cout << "\t Enter name: ";
        cin.ignore(); // To clear the newline character in the input buffer
        getline(cin, patient_name);
        cout << "\t Enter contact no.: ";
        cin >> patient_Cno;
        cout << "\t Describe problem: ";
        cin.ignore(); // To clear the newline character in the input buffer
        getline(cin, patient_problem);

        Patient patient1(patient_id, patient_name, patient_Cno, patient_problem);

        // Allocate a doctor to the patient
        cout << "Allocate Doctor to Patient Information:\n";
        int doctor_id;
        string doctor_name;
        string doctor_Cno;
        string doctor_role;

        cout << "\t Enter Doctor ID: ";
        cin >> doctor_id;

        cout << "\t Enter Doctor Name: ";
        cin.ignore();
        getline(cin, doctor_name);

        cout << "\t Enter Doctor Contact Number: ";
        cin >> doctor_Cno;

        cout << "\t Enter Doctor Role: ";
        cin.ignore();
        getline(cin, doctor_role);

        Doctor doctor1(doctor_id, doctor_name, doctor_Cno, doctor_role);

        // Allocate a nurse to the patient
        cout << "Allocate Nurse to Patient:\n";
        int nurse_id;
        string nurse_name;
        string nurse_Cno;
        string nurse_specialty;

        cout << "\t Enter Nurse ID: ";
        cin >> nurse_id;

        cout << "\t Enter Nurse Name: ";
        cin.ignore();
        getline(cin, nurse_name);

        cout << "\t Enter Nurse Contact Number: ";
        cin >> nurse_Cno;

        cout << "\t Enter Nurse Specialty: ";
        cin.ignore();
        getline(cin, nurse_specialty);

        Nurse nurse1(nurse_id, nurse_name, nurse_Cno, nurse_specialty);

        // Payment info
        cout << "Enter Payment Information for a Patient:\n";
        int amount;
        string date;
        string mode;

        cout << "\t Enter Payment Amount: ";
        cin >> amount;

        cout << "\t Enter Payment Date (yyyy-mm-dd): ";
        cin >> date;

        cout << "\t Enter Payment Mode: ";
        cin.ignore();
        getline(cin, mode);

        Payment payment1(amount, date, mode);

        doctors.push_back(doctor1);
        patients.push_back(patient1);
        nurses.push_back(nurse1);

        Entry ent(mainID, doctor1, patient1, nurse1, payment1);
        ent.displayEntryInfo();
        Record.push_back(ent);

        cout << "\n\nIs there any more record? If 'YES', enter 1 else enter 0: ";
        int reco;
        cin >> reco;

        if (reco == 0) {
            break;
        }

        mainID++; // Increment the mainID for the next entry.
    }

    while(1){
    	cout<<"1. Show All Records \n2. Show All Doctor \n3. Show All Patient \n4. Show All Nurses  ";
    	int cs;
    	cin>>cs;
    	if(cs==1){
    		for (int i = 0; i < Record.size(); i++) {
		        cout << "------------******--------\n";
		        Record[i].displayEntryInfo();
		    }
		}
		else if(cs==2){
    		getAllDoctors(doctors);
		}
		else if(cs==3){
    		getAllPatients(patients);
		}
		else if(cs==4){
    		getAllNurces(nurses);
		}
		else{
			return 9;
		}
    	
	}
    return 0;
}


