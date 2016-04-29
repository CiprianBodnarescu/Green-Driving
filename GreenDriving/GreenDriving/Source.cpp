#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
#include<math.h>
#include<time.h>

using namespace std;

//int NumarComponenteVector = 0;
//int NumarTelematicsVector = 0;

class Telematics {
	//folosim unix timestamp
private:
	const int id;
	long long timestamp;
	float latitudine;
	float longitudine;
	float viteza;
public:

	//constructor implicit
	Telematics() :id(0) {
		this->timestamp = 0;
		this->latitudine = 0;
		this->longitudine = 0;
		this->viteza = 0;
	}

	//constructor cu toti parametrii
	Telematics(int Id, long long timestamp, float latitudine, float longitudine, float viteza) :id(Id) {
		this->timestamp = timestamp;
		this->latitudine = latitudine;
		this->longitudine = longitudine;
		this->viteza = viteza;
	}

	//destructorul telematics
	~Telematics() {
		//nu avem nimic alocat dinamic
	}

	//getteri Telematics
	int getID() {
		return this->id;
	}

	long long getTimeStamp() {
		return this->timestamp;
	}

	float getLatitudine() {
		return this->latitudine;
	}

	float getLongitudine() {
		return this->longitudine;
	}

	float getViteza() {
		return this->viteza;
	}

	//setteri Telematics
	void setTimestamp(double a) {
		this->timestamp = a;
	}

	void setLatitudine(float a) {
		this->latitudine = a;
	}

	void setLongitudine(float a) {
		this->longitudine = a;
	}

	void setViteza(float a) {
		this->viteza = a;
	}

	//constructor de copiere Telematics
	Telematics(const Telematics& t) :id(t.id){
		this->timestamp = t.timestamp;
		this->latitudine = t.latitudine;
		this->longitudine = t.longitudine;
		this->viteza = t.viteza;
	}

	//suprainarcare operator = Telematics
	Telematics& operator=(Telematics& t) {
		this->timestamp = t.timestamp;
		this->latitudine = t.latitudine;
		this->longitudine = t.longitudine;
		this->viteza = t.viteza;

		return *this;
	}

	//supraincarcare operator << Telematics
	friend ostream& operator<<(ostream& afiseaza, Telematics& t) {
		afiseaza << endl << "Id autovehicul: " << t.getID();
		afiseaza << endl << "Timestamp: " << t.getTimeStamp();
		afiseaza << endl << "Latitudine: " << t.getLatitudine();
		afiseaza << endl << "Longitudine: " << t.getLongitudine();
		afiseaza << endl << "Viteza: " << t.getViteza() << endl;

		return afiseaza;
	}

	//supraincarcare operator >> Telematics
	friend istream& operator>>(istream& scrie, Telematics& t) {
		cout << endl << "Noul timestamp dorit: ";
		scrie >> t.timestamp;
		cout << endl << "Noua latitudine dorita: ";
		scrie >> t.latitudine;
		cout << endl << "Noua longitudine dorita: ";
		scrie >> t.longitudine;
		cout << endl << "Noua viteza dorita: ";
		scrie >> t.viteza;

		return scrie;
	}
};

class Autovehicul {
public:
	const int id;
	char* engine;
	float max_speed;
	float engine_cc;
	float avg_consumption_urban;
	float avg_speed_urban;
	float avg_consumption;
	float avg_speed;
	static int nrAutovehicule;

public:

	//constructor fara parametri
	Autovehicul() :id(++nrAutovehicule) {
		this->engine = new char[strlen("FaraNume") + 1];
		strcpy(this->engine, "FaraNume");
		this->max_speed = 0;
		this->engine_cc = 0;
		this->avg_consumption_urban = 0;
		this->avg_speed_urban = 0;
		this->avg_consumption = 0;
		this->avg_speed = 0;
	}

	//constructor auto cu parametru id
	Autovehicul(int Id) :id(Id) {
		this->engine = new char[strlen("FaraNume") + 1];
		strcpy(this->engine, "FaraNume");
		this->max_speed = 0;
		this->engine_cc = 0;
		this->avg_consumption_urban = 0;
		this->avg_speed_urban = 0;
		this->avg_consumption = 0;
		this->avg_speed = 0;
	}

	//constructor cu un parametru
	Autovehicul(char* tip) :id(++nrAutovehicule) {
		this->engine = new char[strlen(tip) + 1];
		strcpy(this->engine, tip);
		this->max_speed = 0;
		this->engine_cc = 0;
		this->avg_consumption_urban = 0;
		this->avg_speed_urban = 0;
		this->avg_consumption = 0;
		this->avg_speed = 0;
	}

	//constructor Autovehicul cu toti parametrii
	Autovehicul(char* Engine, float maxSpeed, float Engine_cc, float avg_consumption_urb,
		float avg_speed_urban, float avg_cons, float avg_speed) :id(++nrAutovehicule) {
		this->engine = new char[strlen(Engine) + 1];
		strcpy(this->engine, Engine);
		this->max_speed = maxSpeed;
		this->engine_cc = Engine_cc;
		this->avg_consumption_urban = avg_consumption_urb;
		this->avg_speed_urban = avg_speed_urban;
		this->avg_consumption = avg_cons;
		this->avg_speed = avg_speed;
	}

	//constructor Autovehicul cu toti parametrii +id
	Autovehicul(int Id, char* Engine, float maxSpeed, float Engine_cc, float avg_consumption_urb,
		float avg_speed_urban, float avg_cons, float avg_speed) :id(Id){
		this->engine = new char[strlen(Engine) + 1];
		strcpy(this->engine, Engine);
		this->max_speed = maxSpeed;
		this->engine_cc = Engine_cc;
		this->avg_consumption_urban = avg_consumption_urb;
		this->avg_speed_urban = avg_speed_urban;
		this->avg_consumption = avg_cons;
		this->avg_speed = avg_speed;

		nrAutovehicule++;
	}

	//destructor
	~Autovehicul() {
		if (this->engine != NULL)
			delete[] this->engine;
		nrAutovehicule--;
	}

	//getter numar autovehicule
	static int getNrAutovehicule() {
		return nrAutovehicule;
	}

	//getter id Autovehicul
	int getId() {
		return this->id;
	}

	//getter tip Motor
	char* getEngine() {
		return this->engine;
	}

	//setter tip Motor
	void setEngine(char* tip) {
		if (this->engine != NULL)
			delete[] this->engine;
		this->engine = new char[strlen(tip) + 1];
		strcpy(this->engine, tip);
		free(tip);
	}

	//getter Viteza maxima
	float getMaxSpeed() {
		return this->max_speed;
	}

	//setter Viteza Maxima
	void setMaxSpeed(float max) {
		this->max_speed = max;
	}

	//getter Capacitate Motor
	float getEngineCC() {
		return this->engine_cc;
	}

	//setter Capacitate Motor
	void setEngineCC(float cc) {
		this->engine_cc = cc;
	}

	//getter Consum Mediu Urban
	float getAvgConsumptionUrban(){
		return this->avg_consumption_urban;
	}

	//setter Consum Mediu Urban
	void setAvgConsumptionUrban(float avg) {
		this->avg_consumption_urban = avg;
	}

	//getter Viteza Medie Urbana
	float getAvgSpeedUrban() {
		return this->avg_speed_urban;
	}

	//setter Viteza Medie Urbana
	void setAvgSpeedUrban(float avg) {
		this->avg_speed_urban = avg;
	}

	//getter Consum Mediu
	float getAvgConsumption() {
		return this->avg_consumption;
	}

	//setter Consum Mediu
	void setAvgConsumption(float avg) {
		this->avg_consumption = avg;
	}

	//getter Viteza Medie
	float getAvgSpeed() {
		return this->avg_speed;
	}

	//setter Viteza Medie
	void setAvgSpeed(float avg) {
		this->avg_speed = avg;
	}

	//constructor de copiere
	Autovehicul(const Autovehicul& a) :id(a.id) {
		this->engine = new char[strlen(a.engine) + 1];
		strcpy(this->engine, a.engine);
		this->max_speed = a.max_speed;
		this->avg_consumption = a.avg_consumption;
		this->avg_consumption_urban = a.avg_consumption_urban;
		this->avg_speed = a.avg_speed;
		this->avg_speed_urban = a.avg_speed_urban;
		this->engine_cc = a.engine_cc;
		nrAutovehicule++;
	}

	//supraincarcare operator =
	Autovehicul& operator=(Autovehicul a) {
		if (this->engine != NULL)
			delete[] this->engine;
		this->engine = new char[strlen(a.engine) + 1];
		strcpy(this->engine, a.engine);
		this->max_speed = a.max_speed;
		this->avg_consumption = a.avg_consumption;
		this->avg_consumption_urban = a.avg_consumption_urban;
		this->avg_speed = a.avg_speed;
		this->avg_speed_urban = a.avg_speed_urban;
		this->engine_cc = a.engine_cc;

		return *this;

	}

	//supraincarcare operator <<
	friend ostream& operator<<(ostream& afiseaza, Autovehicul& a) {
		afiseaza << endl;
		afiseaza << "Tip motor: " << a.getEngine() << endl;
		afiseaza << "Viteza maxima: " << a.getMaxSpeed() << endl;
		afiseaza << "Capacitate Motor: " << a.getEngineCC() << endl;
		afiseaza << "Consum mediu urban: " << a.getAvgConsumptionUrban() << endl;
		afiseaza << "Viteza medie urbana: " << a.getAvgSpeedUrban() << endl;
		afiseaza << "Consum mediu: " << a.getAvgConsumption() << endl;
		afiseaza << "Viteza medie: " << a.getAvgSpeed() << endl;

		return afiseaza;
	}

	//supraincarcare operator >>
	friend istream& operator>>(istream& citeste, Autovehicul& a) {
		if (a.engine != NULL)
			delete[] a.engine;

		char aux[50];
		cout << endl << "Noul tip de motor: ";
		citeste >> aux;
		a.engine = new char[strlen(aux) + 1];
		strcpy(a.engine, aux);

		cout << endl << "Noua viteza maxima: ";
		citeste >> a.max_speed;

		cout << endl << "Noua capacitate a motorului: ";
		citeste >> a.engine_cc;

		cout << endl << "Noul consum mediu urban: ";
		citeste >> a.avg_consumption_urban;

		cout << endl << "Noua viteza medie urbana: ";
		citeste >> a.avg_speed_urban;

		cout << endl << "Noul consum mediu: ";
		citeste >> a.avg_consumption;

		cout << endl << "Noua viteza medie: ";
		citeste >> a.avg_speed;

		return citeste;

	}


};
//Pentru autovehicul mai ramane de supraincarcat operatorii

class String {
private:
	char* ps;
	int length;
public:

	//constructor fara parametri
	String() {
		this->ps = NULL;
		this->length = 0;
	}

	//constructor cu un parametru
	String(char* str) {
		this->length = strlen(str);
		this->ps = new char[strlen(str) + 1];
		strcpy(this->ps, str);
	}

	//destructorul String
	~String() {
		if (this->ps != NULL)
			delete[] this->ps;

	}

	//getter lungime sir
	int getLength() {
		return this->length;
	}

	//getter sir de caractere
	char* getCString() {
		return this->ps;
	}

	//setter sir de caractere
	void setCString(char* sir) {
		if (this->ps != NULL)
			delete[] this->ps;
		this->ps = new char[strlen(sir) + 1];
		strcpy(this->ps, sir);
		this->length = strlen(this->ps);

	}

	//supraincarcare operator <<
	friend ostream& operator<<(ostream& afiseaza, String s) {
		afiseaza << endl << "Sir de caractere: " << s.getCString() << endl;
		afiseaza << "Lungime sir de caractere: " << s.getLength() << endl;

		return afiseaza;
	}

	//supraincarcare operator >>
	friend istream& operator >> (istream& scrie, String& s) {
		if (s.ps != NULL)
			delete[] s.ps;
		char aux[100];
		cout << "Noul sir de caractere: ";
		scrie >> aux;
		s.ps = new char[strlen(aux) + 1];
		strcpy(s.ps, aux);
		s.length = strlen(s.ps);
		cout << "Noua lungime este de " << s.length << " caractere" << endl;

		return scrie;
	}

	//Constructorul de copiere String
	String(String& strSrc) {
		this->length = strSrc.length;
		if (strSrc.ps != NULL)
		{
			this->ps = new char[this->length + 1];
			strcpy(this->ps, strSrc.ps);
		}
		else
			this->ps = NULL;
	}

	//Supraincarcare operator = String
	String& operator=(String& strSrc) {
		this->length = strSrc.length;
		if (this->ps != NULL)
			delete[] this->ps;
		this->ps = new char[strlen(strSrc.ps) + 1];
		strcpy(this->ps, strSrc.ps);

		return *this;
	}

	//supraincarcare operator --
	void operator--() {

		string a;
		a = this->ps;
		a = a.substr(a.find(":") + 2);
		if (this->ps != NULL)
			delete[] this->ps;
		char* b = strdup(a.c_str());
		this->ps = new char[strlen(b) + 1];
		strcpy(this->ps, b);
		this->length = strlen(this->ps);
	}
};

class Geofence {
protected:
	char* tip;
	char* restrictie;

public:
	virtual void GeofenceAfisare() {
		cout << "";
	}

	virtual void SetGeofence() {

		cout << endl << "Noua restrictie Geofence dorita: ";
		char aux2[50];
		cin >> aux2;
		if (this->restrictie != NULL)
			delete[] this->restrictie;
		this->restrictie = new char[strlen(aux2) + 1];
		strcpy(this->restrictie, aux2);
	}

	//constructor fara paramteri
	Geofence() {
		this->tip = NULL;
		this->restrictie = NULL;
	}

	//constructor cu parametrul tip - fara cel de al doilea parametru de tip int => restrictie red!
	Geofence(char* tip) {
		this->tip = new char[strlen(tip) + 1];
		strcpy(this->tip, tip);
		this->restrictie = new char[strlen("red") + 1];
		strcpy(this->restrictie, "red");
	}

	//constructor cu toti parametrii - al doilea parametru este de tip int si aflam astfel ca 
	//acest constructor creeaza un obiect cu restrictia verde
	Geofence(char* tip, int ok) {
		this->tip = new char[strlen(tip) + 1];
		strcpy(this->tip, tip);
		this->restrictie = new char[strlen("green") + 1];
		strcpy(this->restrictie, "green");
	}

	//destructor Geofence
	~Geofence() {
		if (this->tip != NULL)
			delete[] this->tip;
		if (this->restrictie != NULL)
			delete[] this->restrictie;

	}

	//constructor de copiere Geofence
	Geofence(const Geofence& g) {
		this->tip = new char[strlen(g.tip) + 1];
		strcpy(this->tip, g.tip);
		this->restrictie = new char[strlen(g.restrictie) + 1];
		strcpy(this->restrictie, g.restrictie);
	}

	//supraincarcare operator = Geofence
	Geofence& operator=(Geofence& g) {
		if (this->tip != NULL)
			delete[] this->tip;
		this->tip = new char[strlen(g.tip) + 1];
		strcpy(this->tip, g.tip);

		if (this->restrictie != NULL)
			delete[] this->restrictie;
		this->restrictie = new char[strlen(g.restrictie) + 1];
		strcpy(this->restrictie, g.restrictie);

		return *this;
	}

	//getteri Geofence
	char* getTip() {
		return this->tip;
	}

	char* getRestrictie() {
		return this->restrictie;
	}

	//getteri Dreptunghi
	virtual float getSLatitudine() {
		return -1;
	}

	virtual float getSLongitudine() {
		return -1;
	}

	virtual float getDLatitudine() {
		return -1;
	}

	virtual float getDLongitudine() {
		return -1;
	}

	//getteri Cerc
	virtual float getLatitudine() {
		return -1;
	}

	virtual float getLongitudine() {
		return -1;
	}

	virtual float getRadius() {
		return -1;
	}

	//setteri Geofence
	void setTip(char* tip) {
		if (this->tip != NULL)
			delete[] this->tip;
		this->tip = new char[strlen(tip) + 1];
		strcpy(this->tip, tip);
	}

	void setRestrictie(char* restr) {
		if (this->restrictie != NULL)
			delete[] this->restrictie;
		this->restrictie = new char[strlen(restr) + 1];
		strcpy(this->restrictie, restr);
	}

	//supraincarcarea operatorului << Geofence
	friend ostream& operator<<(ostream& afiseaza, Geofence& g) {
		afiseaza << endl << "Tip Geofence: " << g.getTip() << endl;
		afiseaza << "Restrictie Geofence: " << g.getRestrictie() << endl;

		return afiseaza;
	}

	//supraincarcarea operator >> Geofence
	friend istream& operator>>(istream& scrie, Geofence& g) {
		cout << endl << "Noul tip Geofence dorit: ";
		char aux[50];
		scrie >> aux;
		if (g.tip != NULL)
			delete[] g.tip;
		g.tip = new char[strlen(aux) + 1];
		strcpy(g.tip, aux);

		cout << endl << "Noua restrictie Geofence dorita: ";
		char aux2[50];
		scrie >> aux2;
		if (g.restrictie != NULL)
			delete[] g.restrictie;
		g.restrictie = new char[strlen(aux2) + 1];
		strcpy(g.restrictie, aux2);

		return scrie;
	}

};

class Cerc :public Geofence {
private:
	float latitudine;
	float longitudine;
	float radius;
public:
	//functia de afisare a obiectului Cerc
	void GeofenceAfisare() {
		cout << *this;
	}

	//constructorul fara parametri Cerc pentru restrctie rosie
	Cerc() :Geofence("circle") {
		this->latitudine = 0;
		this->longitudine = 0;
		this->radius = 0;
	}

	//constructorul fara parametri Cerc pentru restrictie verde(parametru int! )
	Cerc(int ok) :Geofence("circle", ok) {
		this->latitudine = 0;
		this->longitudine = 0;
		this->radius = 0;
	}

	//constructorul cu toti parametrii cu restrictia rosie
	Cerc(float lat, float longi, float radius) :Geofence("circle") {
		this->latitudine = lat;
		this->longitudine = longi;
		this->radius = radius;
	}

	//constructorul cu toti parametrii cu restrictia verde(+ parametru int)
	Cerc(float lat, float longi, float radius, int ok) :Geofence("circle", ok) {
		this->latitudine = lat;
		this->longitudine = longi;
		this->radius = radius;
	}

	//destructorul Cerc
	~Cerc() {
		//nu avem nimic alocat dinamic
	}

	//constructorul de copiere
	Cerc(const Cerc& c){
		this->tip = new char[strlen(c.tip) + 1];
		strcpy(this->tip, c.tip);

		this->restrictie = new char[strlen(c.restrictie) + 1];
		strcpy(this->restrictie, c.restrictie);

		this->latitudine = c.latitudine;
		this->longitudine = c.longitudine;
		this->radius = c.radius;
	}

	//supraincarcare operator = Cerc
	Cerc& operator=(Cerc& c) {
		if (this->tip != NULL)
			delete[] this->tip;
		this->tip = new char[strlen(c.tip) + 1];
		strcpy(this->tip, c.tip);

		if (this->restrictie != NULL)
			delete[] this->restrictie;
		this->restrictie = new char[strlen(c.restrictie) + 1];
		strcpy(this->restrictie, c.restrictie);

		this->latitudine = c.latitudine;
		this->longitudine = c.longitudine;
		this->radius = c.radius;

		return *this;
	}

	//getteri Cerc
	float getLatitudine() {
		return this->latitudine;
	}

	float getLongitudine() {
		return this->longitudine;
	}

	float getRadius() {
		return this->radius;
	}

	//setteri Cerc
	void setLatitudine(float a) {
		this->latitudine = a;
	}

	void setLongitudine(float a) {
		this->longitudine = a;
	}

	void setRadius(float a) {
		this->radius = a;
	}

	//supraincarcare operator << Cerc
	friend ostream& operator<<(ostream& afiseaza, Cerc& c) {
		afiseaza << endl << "Tip: " << c.getTip() << endl;
		afiseaza << "Restrictie cerc: " << c.getRestrictie() << endl;
		afiseaza << "Latitudine punct: " << c.getLatitudine() << endl;
		afiseaza << "Longitudine punct: " << c.getLongitudine() << endl;
		afiseaza << "Radius cerc: " << c.getRadius() << endl;

		return afiseaza;
	}

	//supraincarcare operator >> Cerc
	friend istream& operator>>(istream& scrie, Cerc& c) {
		/*cout << endl << "Noul tip dorit: ";
		char aux[50];
		scrie >> aux;
		aux[strlen(aux) + 1] = '\0';*/

		/*if (c.tip != NULL)
		delete[] c.tip;
		c.tip = new char[strlen(aux) + 1];
		strcpy(c.tip, aux);*/


		cout << endl << "Noua restrictie dorita: ";
		char aux2[50];
		scrie >> aux2;

		c.setRestrictie(aux2);

		cout << endl << "Noua latitudine dorita: ";
		scrie >> c.latitudine;

		cout << endl << "Noua longitudine dorita: ";
		scrie >> c.longitudine;

		cout << endl << "Noul radius dorit: ";
		scrie >> c.radius;

		return scrie;
	}

	void SetGeofence() {
		cout << endl << "Noua restrictie dorita: ";
		char aux2[50];
		cin >> aux2;

		setRestrictie(aux2);

		cout << endl << "Noua latitudine dorita: ";
		cin >> this->latitudine;

		cout << endl << "Noua longitudine dorita: ";
		cin >> this->longitudine;

		cout << endl << "Noul radius dorit: ";
		cin >> this->radius;
	}
};

class Dreptunghi :public Geofence {
private:
	float slatitudine;
	float slongitudine;
	float dlatitudine;
	float dlongitudine;
public:

	void GeofenceAfisare() {
		cout << *this;
	}

	//constructor fara parametri pentru restrictie rosie
	Dreptunghi() :Geofence("rectangle") {
		this->slatitudine = 0;
		this->slongitudine = 0;
		this->dlatitudine = 0;
		this->dlongitudine = 0;
	}

	//constructor fara parametri pentru restrictie verde ( parametrul intn ok)
	Dreptunghi(int ok) :Geofence("rectangle", ok) {
		this->slatitudine = 0;
		this->slongitudine = 0;
		this->dlatitudine = 0;
		this->dlongitudine = 0;
	}

	//constructor Dreptunghi cu toti parametrii - restrictia red
	Dreptunghi(float Slatitudine, float Slongitudine, float Dlatitudine, float Dlongitudine) :Geofence("rectangle") {
		this->slatitudine = Slatitudine;
		this->slongitudine = Slongitudine;
		this->dlatitudine = Dlatitudine;
		this->dlongitudine = Dlongitudine;
	}

	//constructor Dreptunghi cu toti parametrii + in ok - restrictia green
	Dreptunghi(float Slatitudine, float Slongitudine, float Dlatitudine, float Dlongitudine, int ok) :Geofence("rectangle", ok) {
		this->slatitudine = Slatitudine;
		this->slongitudine = Slongitudine;
		this->dlatitudine = Dlatitudine;
		this->dlongitudine = Dlongitudine;
	}

	//destructor Dreptunghi
	~Dreptunghi() {
		//nu este nimic alocat dinamic pentru a fi dezalocat
	}

	//constructorul de copiere Dreptunghi
	Dreptunghi(const Dreptunghi& d) {
		this->tip = new char[strlen(d.tip) + 1];
		strcpy(this->tip, d.tip);

		this->restrictie = new char[strlen(d.restrictie) + 1];
		strcpy(this->restrictie, d.restrictie);

		this->slatitudine = d.slatitudine;
		this->slongitudine = d.slongitudine;
		this->dlatitudine - d.dlatitudine;
		this->dlongitudine = d.dlongitudine;
	}

	//supraincarcare operator = Dreptunghi
	Dreptunghi& operator=(Dreptunghi& d) {
		if (this->tip != NULL)
			delete[] this->tip;
		this->tip = new char[strlen(d.tip) + 1];
		strcpy(this->tip, d.tip);

		if (this->restrictie != NULL)
			delete[] this->restrictie;
		this->restrictie = new char[strlen(d.restrictie) + 1];
		strcpy(this->restrictie, d.restrictie);

		this->slatitudine = d.slatitudine;
		this->slongitudine = d.slongitudine;
		this->dlatitudine = d.dlatitudine;
		this->dlongitudine = d.dlongitudine;

		return *this;
	}

	//getteri Dreptunghi
	float getSLatitudine() {
		return this->slatitudine;
	}

	float getSLongitudine() {
		return this->slongitudine;
	}

	float getDLatitudine() {
		return this->dlatitudine;
	}

	float getDLongitudine() {
		return this->dlongitudine;
	}

	//setteri Dreptunghi
	void setSLatitudine(float a) {
		this->slatitudine = a;
	}

	void setSLongitudine(float a) {
		this->slongitudine = a;

	}

	void setDLatitudine(float a) {
		this->dlatitudine = a;
	}

	void setDLongitudine(float a) {
		this->dlongitudine = a;
	}

	//supraincarcare operator << Dreptrunghi
	friend ostream& operator<<(ostream& afiseaza, Dreptunghi& d) {
		afiseaza << endl << "Tip Geofence: " << d.getTip() << endl;
		afiseaza << "Restrictie Dreptunghi: " << d.getRestrictie() << endl;
		afiseaza << "Latitudine Stanga-Sus: " << d.getSLatitudine() << endl;
		afiseaza << "Longitudine Stanga-Sus: " << d.getSLongitudine() << endl;
		afiseaza << "Latitudine Dreapta-Jos: " << d.getDLatitudine() << endl;
		afiseaza << "Longitudine Dreapta-Jos: " << d.getDLongitudine() << endl;

		return afiseaza;
	}

	//supraincarcare operator >> Dreptunghi
	friend istream& operator>>(istream& scrie, Dreptunghi& d) {
		if (d.restrictie != NULL)
			delete[] d.restrictie;
		char aux[15];
		cout << "Noua restrictie dorita pentru dreptunghi: ";
		scrie >> aux;
		d.restrictie = new char[strlen(aux) + 1];
		strcpy(d.restrictie, aux);

		cout << "Noua latitudine Stanga-Sus dorita: ";
		scrie >> d.slatitudine;

		cout << "Noua longitudine Stanga-Sus dorita: ";
		scrie >> d.slongitudine;

		cout << "Noua latitudine Dreapta-Jos dorita: ";
		scrie >> d.dlatitudine;

		cout << "Noua longitudine Dreapta-Jos dorita: ";
		scrie >> d.dlongitudine;

		return scrie;
	}

	void SetGeofence() {
		cout << endl << "Noua restrictie dorita: ";
		char aux2[50];
		cin >> aux2;

		setRestrictie(aux2);

		cout << "Noua latitudine Stanga-Sus dorita: ";
		cin >> this->slatitudine;

		cout << "Noua longitudine Stanga-Sus dorita: ";
		cin >> this->slongitudine;

		cout << "Noua latitudine Dreapta-Jos dorita: ";
		cin >> this->dlatitudine;

		cout << "Noua longitudine Dreapta-Jos dorita: ";
		cin >> this->dlongitudine;
	}
};

int Autovehicul::nrAutovehicule = 0;

class FunctiiGlobale {
public:
	//citirea obiectelor auto din fisier binar
	static vector<Autovehicul> getBinAutovehicule(char* numeFisier, vector<Autovehicul> &autovehicule) {

		ifstream f;
		f.open(numeFisier, ios::in | ios::binary);
		if (!f.is_open())
			cout << endl << "Fisierul binar de autovehicule nu se poate deschide";
		else {
			int id, nrCaractere;
			char Engine[50];
			float MaxSpeed, EngineCC, AvgConsUrban, AvgSpeedUrban, AvgCons, AvgSpeed;
			f.read((char*)&id, sizeof(int));
			f.read((char*)&nrCaractere, sizeof(int));
			f.read(Engine, nrCaractere*sizeof(char));
			f.read((char*)&MaxSpeed, sizeof(float));
			f.read((char*)&EngineCC, sizeof(float));
			f.read((char*)&AvgConsUrban, sizeof(float));
			f.read((char*)&AvgSpeedUrban, sizeof(float));
			f.read((char*)&AvgCons, sizeof(float));
			f.read((char*)&AvgSpeed, sizeof(float));
			while (!f.eof()) {

				Autovehicul temp(id, Engine, MaxSpeed, EngineCC, AvgConsUrban, AvgSpeedUrban, AvgCons, AvgSpeed);
				autovehicule.push_back(temp);

				f.read((char*)&id, sizeof(int));
				f.read((char*)&nrCaractere, sizeof(int));
				f.read(Engine, nrCaractere*sizeof(char));
				f.read((char*)&MaxSpeed, sizeof(float));
				f.read((char*)&EngineCC, sizeof(float));
				f.read((char*)&AvgConsUrban, sizeof(float));
				f.read((char*)&AvgSpeedUrban, sizeof(float));
				f.read((char*)&AvgCons, sizeof(float));
				f.read((char*)&AvgSpeed, sizeof(float));
			}
			cout << endl << "Citirea din binar reusita";
		}
		return autovehicule;
	}
	//citirea obiectelor auto din fisier text
	static vector<Autovehicul> getAutovehicule(char* numeFisier, vector<Autovehicul> &autovehicule) {

		ifstream f;
		f.open(numeFisier, ios::in);
		if (!f.is_open())
			cout << endl << "Eroare la deschidere fisier" << endl;
		else {

			while (!f.eof()) {

				//citire id din fisier
				string autoID;
				getline(f, autoID);
				if (autoID == "")
					return autovehicule;
				autoID = autoID.substr(autoID.find("o") + 1);
				int autoID2 = stoi(autoID);


				//citire tipul de motor din fisier
				string Engine;
				getline(f, Engine);
				Engine = Engine.substr(Engine.find(":") + 2);
				char* buffer;
				buffer = strdup(Engine.c_str());

				//citire viteza maxima
				string maxspeed;
				getline(f, maxspeed);
				maxspeed = maxspeed.substr(maxspeed.find(":") + 2);
				float maxspeed2 = stof(maxspeed);

				//citire capacitate motor
				string enginecc;
				getline(f, enginecc);
				enginecc = enginecc.substr(enginecc.find(":") + 2);
				float enginecc2 = stof(enginecc);

				//citire Consum mediu urban
				string avgconsurban;
				getline(f, avgconsurban);
				avgconsurban = avgconsurban.substr(avgconsurban.find(":") + 2);
				float avgconsurban2 = stof(avgconsurban);

				//citire Viteza medie urbana
				string avgspeedurban;
				getline(f, avgspeedurban);
				avgspeedurban = avgspeedurban.substr(avgspeedurban.find(":") + 2);
				float avgspeedurban2 = stof(avgspeedurban);

				//citire Consum mediu
				string avgcons;
				getline(f, avgcons);
				avgcons = avgcons.substr(avgcons.find(":") + 2);
				float avgcons2 = stof(avgcons);

				//citire Viteza medie
				string avgspeed;
				getline(f, avgspeed);
				avgspeed = avgspeed.substr(avgspeed.find(":") + 2);
				float avgspeed2 = stof(avgspeed);

				Autovehicul temp(autoID2, buffer, maxspeed2, enginecc2, avgconsurban2, avgspeedurban2,
					avgcons2, avgspeed2);
				autovehicule.push_back(temp);
				delete buffer;

			}
			f.close();
			Autovehicul::nrAutovehicule = autovehicule.size();
			return autovehicule;
		}
	}
	//citirea obiectelor din fisier pentru Telematics
	static vector<Telematics>& getTelematics(char* numeFisier, vector<Telematics> &telematics) {
		//Telematics* telematics;


		ifstream f;

		f.open(numeFisier, ios::in);

		if (!f.is_open())
			cout << "Probleme la deschiderea fisierului Telematics" << endl;
		else {

			while (!f.eof()) {



				//id
				string ID;
				getline(f, ID);
				ID = ID.substr(ID.find("o") + 1);
				int ID2 = stoi(ID);

				//timestamp
				string timestamp;
				getline(f, timestamp);
				long long timestamp2 = stoll(timestamp);

				//latitudine
				string lat;
				getline(f, lat);
				float latitudine = stof(lat);

				//longitudine
				string longi;
				getline(f, longi);
				float longitudine = stof(longi);

				//viteza
				string vit;
				getline(f, vit);
				float viteza = stof(vit);

				Telematics temp(ID2, timestamp2, latitudine, longitudine, viteza);

				telematics.push_back(temp);

			}
		}
		f.close();
		//cout << "Terminat" << endl;
		return telematics;
	}
	//citirea obiectelor din fisier text pentru Geofence
	static vector<Geofence*>& getGeofence(char* numeFisier, vector<Geofence*> &geofence) {
		ifstream f;

		f.open(numeFisier, ios::in);
		if (!f.is_open())
			cout << endl << "Citirea din fisierul text Geofence esuata" << endl;
		else {
			while (!f.eof()) {

				//tip
				string tip;
				getline(f, tip);
				if (tip == "")
					return geofence;
				tip = tip.substr(tip.find(":") + 2);
				char* buffer;
				buffer = strdup(tip.c_str());

				if (strcmp(buffer, "circle") == 0) {

					//restrictie
					string restrictie;
					getline(f, restrictie);
					restrictie = restrictie.substr(restrictie.find(":") + 2);
					char* buffer2;
					buffer2 = strdup(restrictie.c_str());

					//latitudine si longitudine
					string linie, latitudine, longitudine;
					getline(f, linie);
					linie = linie.substr(linie.find(":") + 2);
					latitudine = linie.substr(0, linie.find(";"));
					longitudine = linie.substr(linie.find(";") + 1);
					float latitudine2 = stof(latitudine);
					float longitudine2 = stof(longitudine);

					//radius
					string rad;
					getline(f, rad);
					rad = rad.substr(rad.find(":") + 2);
					rad = rad.substr(0, rad.find("k"));
					float radius = stof(rad);

					if (strcmp(buffer2, "red") == 0) {
						Cerc *temp = new Cerc(latitudine2, longitudine2, radius);
						geofence.push_back(temp);
					}
					else
						if (strcmp(buffer2, "green") == 0) {
							Cerc *temp = new Cerc(latitudine2, longitudine2, radius, 1);
							geofence.push_back(temp);
						}

					delete buffer2;
				}
				else
					if (strcmp(buffer, "rectangle") == 0) {

						//restrictie
						string restrictie;
						getline(f, restrictie);
						restrictie = restrictie.substr(restrictie.find(":") + 2);
						char* buffer2;
						buffer2 = strdup(restrictie.c_str());

						string linie1, slatitudine, slongitudine;
						getline(f, linie1);
						linie1 = linie1.substr(linie1.find(":") + 2);
						slatitudine = linie1.substr(0, linie1.find(";"));
						slongitudine = linie1.substr(linie1.find(";") + 1);
						float slatitudine2 = stof(slatitudine);
						float slongitudine2 = stof(slongitudine);

						string linie2, dlatitudine, dlongitudine;
						getline(f, linie2);
						linie2 = linie2.substr(linie2.find(":") + 2);
						dlatitudine = linie2.substr(0, linie2.find(";"));
						dlongitudine = linie2.substr(linie2.find(";") + 1);
						float dlatitudine2 = stof(dlatitudine);
						float dlongitudine2 = stof(dlongitudine);

						if (strcmp(buffer2, "red") == 0) {
							Dreptunghi *temp = new Dreptunghi(slatitudine2, slongitudine2, dlatitudine2, dlongitudine2);
							geofence.push_back(temp);
						}
						else
							if (strcmp(buffer2, "green") == 0) {
								Dreptunghi *temp = new Dreptunghi(slatitudine2, slongitudine2, dlatitudine2, dlongitudine2, 1);
								geofence.push_back(temp);
							}

					}

				delete buffer;
				//cout << endl << "Citire din fisier text Geofence reusita" << endl;
			}
		}
		return geofence;
	}
	//salvarea autovehiculelor intr-un fisier text
	static void saveAutovehicule(char* NumeFisier, vector<Autovehicul> &autovehicule) {
		ofstream f;
		f.open(NumeFisier, ios::out);
		if (!f.is_open())
			cout << "Probleme la deschiderea fisierului!";
		else {

			for (int i = 0; i < autovehicule.size(); i++) {

				f << "auto" << autovehicule[i].getId() << endl;
				f << "engine: " << autovehicule[i].getEngine() << endl;
				f << "max_speed: " << autovehicule[i].getMaxSpeed() << endl;
				f << "engine_cc: " << autovehicule[i].getEngineCC() << endl;
				f << "avg_consumption_urban: " << autovehicule[i].getAvgConsumptionUrban() << endl;
				f << "avg_speed_urban: " << autovehicule[i].getAvgSpeedUrban() << endl;
				f << "avg_consumption: " << autovehicule[i].getAvgConsumption() << endl;
				f << "avg_speed: " << autovehicule[i].getAvgSpeed() << endl;
			}

			cout << endl << "Salvarea autovehiculelor in fisier text a avut loc cu succes" << endl;
		}
		f.close();
	}
	//salvarea autovehiculelor intr-un fisier binar
	static void saveBinAutovehicule(char* NumeFisier, vector<Autovehicul> &autovehicule) {
		ofstream f;
		f.open(NumeFisier, ios::out, ios::binary);
		if (!f.is_open())
			cout << "Probleme la deschiderea fisierului!";
		else {
			for (int i = 0; i < autovehicule.size(); i++) {
				f.write((char*)&(autovehicule[i].id), sizeof(int));
				int nrCaractere = strlen(autovehicule[i].engine) + 1;
				f.write((char*)&nrCaractere, sizeof(int));
				f.write(autovehicule[i].engine, nrCaractere);
				f.write((char*)&autovehicule[i].max_speed, sizeof(float));
				f.write((char*)&autovehicule[i].engine_cc, sizeof(float));
				f.write((char*)&autovehicule[i].avg_consumption_urban, sizeof(float));
				f.write((char*)&autovehicule[i].avg_speed_urban, sizeof(float));
				f.write((char*)&autovehicule[i].avg_consumption, sizeof(float));
				f.write((char*)&autovehicule[i].avg_speed, sizeof(float));
			}
			f.close();
			cout << endl << "Salvarea in fisierul binar a autovehiculelor a avut loc cu succes" << endl;
		}
	}
	//raport 
	static void getRaportCoordonataMedie(char* NumeRaport, vector<Autovehicul>&autovehicule, int id, float &SumaLatitudine, float &SumaLongitudine, float &Nr) {

		ofstream f;
		f.open(NumeRaport, ios::out);

		if (!f.is_open())
			cout << endl << "Probleme la deschiderea fisierului pentru raport" << endl;

		else {
			f << "Ati ales autovehiculul cu urmatoarele caracteristici\n";


			f << "auto" << autovehicule[id].getId() << endl;
			f << "engine: " << autovehicule[id].getEngine() << endl;
			f << "max_speed: " << autovehicule[id].getMaxSpeed() << endl;
			f << "engine_cc: " << autovehicule[id].getEngineCC() << endl;
			f << "avg_consumption_urban: " << autovehicule[id].getAvgConsumptionUrban() << endl;
			f << "avg_speed_urban: " << autovehicule[id].getAvgSpeedUrban() << endl;
			f << "avg_consumption: " << autovehicule[id].getAvgConsumption() << endl;
			f << "avg_speed: " << autovehicule[id].getAvgSpeed() << endl;

			f << "Autovehiculul ales a trecut prin " << Nr << " puncte telematice si are ca si coordonate medii:";
			f << "\nLatitudine medie: " << SumaLatitudine;
			f << "\nLongitudine medie: " << SumaLongitudine;
		}
		f.close();
		cout << endl << "Raportul a fost facut cu succes" << endl;
	}

	static void FunctieEco(int id, vector<Autovehicul>&autovehicule, vector<Telematics>&telematics, vector<Geofence*>&geofence, int &Verde, int &Rosu) {
		Verde = 0;
		Rosu = 0;
		for (int i = 0; i < telematics.size(); i++)
			if (autovehicule[id - 1].getId() == telematics[i].getID()) {
				for (int j = 0; j < geofence.size(); j++)
				{
					if (strcmp(geofence[j]->getTip(), "rectangle") == 0)
					{
						if (telematics[i].getLatitudine() <= geofence[j]->getSLatitudine()
							&& telematics[i].getLongitudine() >= geofence[j]->getSLongitudine()
							&& telematics[i].getLatitudine() >= geofence[j]->getDLatitudine()
							&& telematics[i].getLongitudine() <= geofence[j]->getDLongitudine())
						{
							if (strcmp(geofence[j]->getRestrictie(), "green") == 0)
								Verde++;
							else
								if (strcmp(geofence[j]->getRestrictie(), "red") == 0)
									Rosu++;
						}
					}
					else {
						if (strcmp(geofence[j]->getTip(), "circle") == 0)
						{
							float latitudineC = 3.1415*geofence[j]->getLatitudine() / 180.0;
							float longitudineC = 3.1415*geofence[j]->getLongitudine() / 180.0;
							float latitudineP = 3.1415*telematics[i].getLatitudine() / 180.0;
							float longitudineP = 3.1415*telematics[i].getLongitudine() / 180.0;
							float a = pow(sin((latitudineC - latitudineP) / 2), 2) + cos(latitudineC)*cos(latitudineP)*pow(sin((longitudineC - longitudineP) / 2), 2);
							float b = 2 * atan2(sqrt(a), sqrt(1 - a));
							float distanta = 6371 * b;
							if (distanta <= geofence[j]->getRadius())
							{
								if (strcmp(geofence[j]->getRestrictie(), "green") == 0)
									Verde++;
								else
									if (strcmp(geofence[j]->getRestrictie(), "red") == 0)
										Rosu++;
							}
						}
					}
				}
			}
		//cout << endl << "Numar puncte verzi: " << Verde;
		//cout << endl << "Numar puncte rosii: " << Rosu << endl;
	}

	static void RaportCoordonataMedie(int id, vector<Autovehicul>&autovehicule, vector<Telematics>&telematics, float &SumaLatitudine, float &SumaLongitudine, float &Nr) {
		Nr = 0;
		SumaLatitudine = 0;
		SumaLongitudine = 0;
		for (int i = 0; i < telematics.size(); i++)
			if (autovehicule[id].getId() == telematics[i].getID()) {
				Nr++;
				SumaLatitudine = SumaLatitudine + telematics[i].getLatitudine();
				SumaLongitudine = SumaLongitudine + telematics[i].getLongitudine();
			}
		SumaLatitudine = SumaLatitudine / Nr;
		SumaLongitudine = SumaLongitudine / Nr;
	}

	static void RaportDispersieViteza(int id, vector<Autovehicul>&autovehicule, vector<Telematics>&telematics, float &dispersie, float &abatere, float &nr) {
		dispersie = 0;
		abatere = 0;
		nr = 0;
		float medie = 0;
		float suma = 0;
		for (int i = 0; i < telematics.size(); i++)
			if ((autovehicule[id].getId() == telematics[i].getID()) && (telematics[i].getViteza() != 0)) {
				medie = medie + telematics[i].getViteza();
				nr++;
			}
		medie = medie / nr;
		for (int i = 0; i < telematics.size(); i++)
			if ((autovehicule[id].getId() == telematics[i].getID()) && (telematics[i].getViteza() != 0)) {
				suma = suma + pow(telematics[i].getViteza() - medie, 2);
			}
		dispersie = suma / nr;
		abatere = sqrt(dispersie);
	}

	static void getRaportDispersieViteza(char* NumeRaport, vector<Autovehicul>&autovehicule, int id, float &dispersie, float &abatere, float &nr) {
		ofstream f;
		f.open(NumeRaport, ios::out);

		if (!f.is_open())
			cout << "Probleme la deschiderea fisierului pentru raport";
		else {
			f << "Ati ales autovehiculul cu urmatoarele caracteristici\n";


			f << "auto" << autovehicule[id].getId() << endl;
			f << "engine: " << autovehicule[id].getEngine() << endl;
			f << "max_speed: " << autovehicule[id].getMaxSpeed() << endl;
			f << "engine_cc: " << autovehicule[id].getEngineCC() << endl;
			f << "avg_consumption_urban: " << autovehicule[id].getAvgConsumptionUrban() << endl;
			f << "avg_speed_urban: " << autovehicule[id].getAvgSpeedUrban() << endl;
			f << "avg_consumption: " << autovehicule[id].getAvgConsumption() << endl;
			f << "avg_speed: " << autovehicule[id].getAvgSpeed() << endl;

			f << "Autovehiculul ales a trecut prin " << nr << " puncte telematice si are ca si coordonate medii:\n";
			f << "Dispersia vitezei acestui autovehicul este: " << dispersie;
			f << "\nAbaterea vitezei acestui autovehicul este: " << abatere;
		}
		f.close();
		cout << endl << "Raportul a fost facut cu succes" << endl;
	}
};

class Meniu {
public:
	void Initializare() {
		int valoare;
		int geo;
		int idAuto = -1;
		int V = 0;
		int R = 0;
		float dispersie;
		float abatere;
		float nr;
		float Nr;
		float SumaLatitudine;
		float SumaLongitudine;
		char* path = new char[255];
		char fisier[50];
		string valCitita;
		string idAutoCitit;

		time_t timp;
		time(&timp);


		vector<Autovehicul> autovehicule;
		vector<Telematics>telematics;
		vector<Geofence*>geofence;

		Autovehicul* temp;
		cout << "Data curenta: " << ctime(&timp);
		cout << endl << "Nume proiect: Green Driving";
		cout << endl << "Autor: Bodnarescu Ciprian";
		cout << endl << "Data creare: 22/01/2016";
		cout << endl << "Universitate: Academia de Studii Economice";
		cout << endl << "Facultate: Cibernetica, Statistica si Informatica Economica";
		cout << endl << "Specializare: Informatica Economica";
		cout << endl << "Descriere: Analiza asupra conducerii ecologice a autovehiculelor";
		cout << endl << "======================================================================" << endl;
		cout << endl << endl << "         Loading...";
		FunctiiGlobale::getTelematics("telematics.txt", telematics);
		valoare = 1;

		while (valoare != 0) {
			cout << endl << endl << "---Meniu Green Driving---";
			cout << endl << endl << "Optiuni:";

			cout << endl;
			cout << endl << " 1. Citire autovehicule din fisierul text dorit";
			cout << endl << " 2. Citire date telematice din fisierul text dorit";
			cout << endl << " 3. Citire restrictii verzi si rosii Geofence";
			cout << endl << " 4. Citire autovehicule din fisierul binar dorit";

			cout << endl;
			cout << endl << " 5. Afisare autovehicule";
			cout << endl << " 6. Afisare restrictii Geofence";

			cout << endl;
			cout << endl << " 7. Setare autovehicul dorit";
			cout << endl << " 8. Setare geofence dorit";

			cout << endl;
			cout << endl << " 9. Salvare autovehicule in fisier text";
			cout << endl << "10. Salvare autovehicule in fisier binar";
			cout << endl;
			cout << endl << "11. Adaugare autovehicul";

			cout << endl << "12. Analizati cat de ecologic conduce un autovehiculul ales";

			cout << endl << "13. Raport despre coordonata medie a unui autovehicul ales";
			cout << endl << "14. Raport despre dispersia si abaterea vitezei unui autovehicul ales";


			cout << endl << "-------------------------------------------------";
			cout << endl << " 0. Exit";

			cout << endl << endl;
			cout << endl << "Inserati numarul optiunii dorite: ";
			cin >> valCitita;
			try{
				valoare = stoi(valCitita);
			}
			catch (...){
				valoare = 15;
			}

			switch (valoare)
			{

			case 1:

				cout << endl << "Alegeti calea catre fisierul text auto. Folositi extensia .txt : ";
				cin.ignore();
				cin.getline(path, 255);

				FunctiiGlobale::getAutovehicule(path, autovehicule);

				cout << endl << "Citire din fisier auto reusita" << endl;
				break;

			case 2:

				cout << endl << "Alegeti calea catre fisierul text Telematics .Folositi extensia .txt : ";
				cin.ignore();
				cin.getline(path, 255);
				FunctiiGlobale::getTelematics(path, telematics);
				cout << endl << "Citire din fisier Telematics reusita" << endl;
				break;

			case 3:
				cout << endl << "Alegeti calea catre fisierul text Geofence. Folositi extensia .txt : ";
				cin.ignore();
				cin.getline(path, 255);
				FunctiiGlobale::getGeofence("geofence.txt", geofence);
				cout << endl << "Citire din fisier Geofence reusita" << endl;
				break;

			case 4:

				cout << endl << "Alegeti calea catre fisierul binar auto. Folositi extensia .dat : ";
				cin.ignore();
				cin.getline(path, 255);
				FunctiiGlobale::getBinAutovehicule(path, autovehicule);
				break;

			case 5:
				if (autovehicule.size() != 0) {
					for (int i = 0; i < autovehicule.size(); i++)
						cout << autovehicule[i] << endl;
				}
				else
					cout << endl << "Nu sunt autovehicule citite" << endl;
				break;

			case 6:
				if (geofence.size() != 0){
					for (int i = 0; i < geofence.size(); i++)
						geofence[i]->GeofenceAfisare();
					cout << endl;
				}
				else{
					cout << endl << "Nu sunt restrictii citite" << endl;
				}
				break;

			case 7:

				cout << endl << "Specificati id-ul autovehiculului pentru actualizare (Id-ul primului autovehicul este 0): ";
				cin >> idAuto;
				if (idAuto >= 0 && idAuto < autovehicule.size()) {
					cin >> autovehicule[idAuto];
					cout << "Setare auto finalizata" << endl;
				}
				else
					cout << endl << "Autovehiculul ales nu exista" << endl;
				break;

			case 8:
				cout << "Specificati a cata restrictie vreti sa o editati: ";
				cin >> geo;
				if (geo >= 1 && geo <= geofence.size()) {
					//cin >> *geofence[geo - 1];
					cout << endl << "Hint: red sau green" << endl;
					geofence[geo - 1]->SetGeofence();
					cout << "Setare finalizata" << endl;
				}
				else
					cout << endl << "Restrictia aleasa nu exista" << endl;

				break;

			case 9:

				cout << endl << "Inserati denumirea fisierului text. Folositi ca extensie .txt: ";
				cin.ignore();
				cin.getline(fisier, 255);
				FunctiiGlobale::saveAutovehicule(fisier, autovehicule);
				break;

			case 10:

				cout << endl << "Inserati denumirea fisierului binar. Folositi ca extensie .dat: ";
				cin.ignore();
				cin.getline(fisier, 255);
				FunctiiGlobale::saveBinAutovehicule(fisier, autovehicule);
				break;

			case 11:
				temp = new Autovehicul(autovehicule.size() + 1);
				cout << endl << "Introduceti datele pentru noul autovehicul" << endl;
				cin >> temp[0];
				autovehicule.push_back(temp[0]);

				cout << endl << "Adaugarea noului autovehicul dorit finalizata" << endl;
				break;

			case 12:
				if (geofence.size() != 0) {
					cout << endl << "Specificati id-ul autovehiculului pentru analiza (Id-ul primului autovehicul este 0): ";
					
					cin >> idAutoCitit;
					try{
						idAuto = stoi(idAutoCitit);
					}
					catch (...){
						idAuto = -1;
					}

					//cin >> idAuto;
					if (idAuto >= 0 && idAuto < autovehicule.size()) {
						FunctiiGlobale::FunctieEco(idAuto + 1, autovehicule, telematics, geofence, V, R);
						cout << endl << "Autovehiculul ales trece prin " << V << " puncte telematice de restrctie verde si prin " << R << " puncte telematice de restrctie rosie" << endl;
						if (R == 0 && V == 0)
							cout << endl << "Autovehiculul nu se misca deloc" << endl;
						else {
							if (R >= V)
								cout << endl << "Autovehiculul nu conduce Eco" << endl;
							else
								cout << endl << "Autovehiculul conduce Eco" << endl;
						}
					}
					else {
						cout << endl << "Nu ati introdus un id valid" << endl;
					}
				}
				else
					cout << endl << "Nu ati citit restrictiile geofence" << endl;
				break;

			case 13:

				cout << endl << "Specificati id-ul autovehiculului pentru analiza (Id-ul primului autovehicul este 0): ";
				cin >> idAutoCitit;
				try{
					idAuto = stoi(idAutoCitit);
				}
				catch (...){
					idAuto = -1;
				}
				//cin >> idAuto;
				if (idAuto >= 0 && idAuto < autovehicule.size()) {
					FunctiiGlobale::RaportCoordonataMedie(idAuto + 1, autovehicule, telematics, SumaLatitudine, SumaLongitudine, Nr);
					cout << endl << "Numarul de puncte telematice este: " << Nr;
					cout << endl << "Latitudine medie: " << SumaLatitudine;
					cout << endl << "Longitudine medie: " << SumaLongitudine;
					cout << endl << "Dati calea pentru salvarea raportului. Extensia trebuie sa fie .txt: ";
					cin.ignore();
					cin.getline(path, 250);
					FunctiiGlobale::getRaportCoordonataMedie(path, autovehicule, idAuto, SumaLatitudine, SumaLongitudine, Nr);
				}
				else
					cout << endl << "Id-ul ales nu exista" << endl;
				break;

			case 14:

				cout << endl << "Specificati id-ul autovehiculului pentru analiza (Id-ul primului autovehicul este 0): ";
				
				cin >> idAutoCitit;
				try{
					idAuto = stoi(idAutoCitit);
				}
				catch (...){
					idAuto = -1;
				}
				//cin >> idAuto;
				if (idAuto >= 0 && idAuto < autovehicule.size()) {
					FunctiiGlobale::RaportDispersieViteza(idAuto + 1, autovehicule, telematics, dispersie, abatere, nr);
					cout << endl << "Dispersia vitezei pentru acest autovehicul este: " << dispersie;
					cout << endl << "Abaterea vitezei pentru acest autovehicul este: " << abatere;
					cout << endl << "Dati calea pentru salvarea raportului. Extensia trebuie sa fie .txt: ";
					cin.ignore();
					cin.getline(path, 250);
					FunctiiGlobale::getRaportDispersieViteza(path, autovehicule, idAuto, dispersie, abatere, nr);
				}
				else
					cout << endl << "Id auto invalid" << endl;
				break;

			case 0:
				cout << endl << "Va multumim!" << endl;
				return;

			default:
				//if (valoare<0 || valoare >14)
					cout << "\nOptiune inexistenta" << endl;
				break;

			}
		}
		delete[] path;
		delete[] temp[0].engine;
		delete[] temp;
	}

};

void main() {
	/*vector<Autovehicul>autovehicule;
	vector<Telematics>telematics;

	getAutovehicule("auto.txt",autovehicule);
	cout << endl << "Citire din auto";*/


	/*for (int i = 0;i < autovehicule.size(); i++)
	cout << autovehicule[i];

	cout << endl << "Numarul de autovehicule in acest moment este de "
	<< Autovehicul::getNrAutovehicule() << " autovehicule sau " << autovehicule.size() << endl;

	saveAutovehicule("auto8.txt", autovehicule);
	saveBinAutovehicule("autobin.dat", autovehicule);
	getBinAutovehicule("autobin.dat",autovehicule);
	cout << endl << "Numarul de autovehicule in acest moment este de "
	<< Autovehicul::getNrAutovehicule() << " autovehicule!";
	for (int i = 0;i < autovehicule.size(); i++)
	cout << autovehicule[i];*/





	/*getTelematics("telematics.txt",telematics);
	cout << endl << "Citire din telematics";*/

	/*for (int i = 0;i < telematics.size();i++)
	cout << telematics[1].getTimeStamp()<< endl;
	cout << endl <<"Numarul de obiecte telematice din acest fisier este: " <<telematics.size() << endl;*/


	/*vector<Geofence*> geofence;
	getGeofence("geofence.txt", geofence);
	cout << endl << "Citire din Geofence";*/


	/*for (int i = 0;i < geofence.size();i++)
	{
	geofence[i]->GeofenceAfisare();
	cout << endl;
	}
	cout << endl << geofence.size() << endl;*/




	Meniu m;
	m.Initializare();


	/*int V = 0;
	int R = 0;
	FunctieEco(1, autovehicule, telematics, geofence, V, R);
	cout << endl << endl << V << "   " << R;*/
}
