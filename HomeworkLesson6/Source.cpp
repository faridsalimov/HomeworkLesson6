#include <iostream>

using namespace std;

class Computer {
	char* compModel = nullptr;
	char* vendor = nullptr;
	char* videocard = nullptr;
	char* monitorname = nullptr;
	int cpuHz;
	int core;
	int ram;
	int diskSize;
	bool SSD;

public:
	Computer() {
		compModel = nullptr;
		vendor = nullptr;
		videocard = nullptr;
		monitorname = nullptr;
		cpuHz = 0;
		core = 0;
		ram = 0;
		diskSize = 0;
		SSD = false;
	};

	Computer(const char* comp, const char* vendor, const char* videocard, const char* monitor, int cpuHz, int core, int ram, int diskSize, bool ssd) {
		SetCompModel(comp);
		SetVendor(vendor);
		SetVideoCard(videocard);
		SetMonitorName(monitor);
		SetCpuHz(cpuHz);
		SetCore(core);
		SetRam(ram);
		SetDiskSize(diskSize);
		SetSSD(ssd);
	}

	void SetCompModel(const char* compModell) {
		compModel = new char[strlen(compModell) + 1] {};
		strcpy_s(compModel, strlen(compModell) + 1, compModell);
	}

	void SetVendor(const char* vendorr) {
		vendor = new char[strlen(vendorr) + 1] {};
		strcpy_s(vendor, strlen(vendorr) + 1, vendorr);
	}

	void SetVideoCard(const char* videoCardd) {
		videocard = new char[strlen(videoCardd) + 1] {};
		strcpy_s(videocard, strlen(videoCardd) + 1, videoCardd);
	}

	void SetMonitorName(const char* monitorr) {
		monitorname = new char[strlen(monitorr) + 1] {};
		strcpy_s(monitorname, strlen(monitorr) + 1, monitorr);
	}

	void SetCpuHz(int cpuHzz) {
		cpuHz = cpuHzz;
	}

	void SetCore(int coree) {
		core = coree;
	}

	void SetRam(int ramm) {
		ram = ramm;
	}

	void SetDiskSize(int diskSizee) {
		diskSize = diskSizee;
	}

	void SetSSD(int ssdd) {
		SSD = ssdd;
	}

	char* GetVendor() {
		return vendor;
	}

	char* GetMonitorName() {
		return monitorname;
	}

	char* GetVideoCard() {
		return videocard;
	}

	char* GetCompModel() {
		return compModel;
	}

	int GetRam() {
		return ram;
	}

	int GetCpuHz() {
		return cpuHz;
	}

	int GetDiskSize() {
		return diskSize;
	}

	int GetCore() {
		return core;
	}

	bool GetSSD() {
		return SSD;
	}

	~Computer() {
		delete[] compModel;
		delete[] videocard;
		delete[] monitorname;
		delete[] vendor;
	}
};

class ComputerStore {
	char* storeName = nullptr;
	char* storeAddress = nullptr;
	Computer** computers = nullptr;
	int size = 0;

public:
	ComputerStore() {
		storeName = nullptr;
		storeAddress = nullptr;
		computers = nullptr;
		size = 0;
	}

	const char* GetstoreName() const { return storeName; }

	const char* GetstoreAddress() const { return storeAddress; }

	Computer** Getcomputers() const { return computers; }

	int Getsize() const { return size; }

	void SetStoreName(const char* value) {
		delete[] storeName;
		storeName = new char[strlen(value) + 1];
		strcpy_s(storeName, strlen(value) + 1, value);
	}

	void SetStoreAddress(const char* value) {
		delete[] storeAddress;
		storeAddress = new char[strlen(value) + 1];
		strcpy_s(storeAddress, strlen(value) + 1, value);
	}

	void SetSize(int sizeother) { size = sizeother; }

	void Print() {
		cout << "[!] (" << storeName << " - " << storeAddress << ") adli magazaya xos gelmisiniz!\n";
		for (int i = 0; i < size; i++)
		{
			cout << "\n========================================" << endl;
			cout << "[!] " << i << "-ci Komputerin Melumatlari: \n";
			cout << ">> Komputerin Modeli: " << computers[i]->GetMonitorName() << "\n>> Vendor: " << computers[i]->GetVendor() << "\n>> Video Card: " << computers[i]->GetVideoCard() << "\n>> Monitor: " << computers[i]->GetMonitorName() << "\n>> CPU Hz: " << computers[i]->GetCpuHz() << "\n>> Core: " << computers[i]->GetCore() << "\n>> RAM: " << computers[i]->GetRam() << "\n>> Disk Olcusu: " << computers[i]->GetDiskSize() << "\n>> SSD: " << computers[i]->GetSSD();
		}

		cout << "\n========================================" << endl;
	}

	void AddComputer(const Computer* comp) {
		Computer** temp = new Computer * [size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = computers[i];
		}

		delete[] computers;
		temp[size] = new Computer(*comp);
		computers = temp;
		temp = nullptr;
		size++;

	}

	~ComputerStore() {
		delete[] storeName;
		delete[] storeAddress;
		for (int i = 0; i < size; i++) delete computers[i];
		delete[] computers;
	}
};

void main() {
	ComputerStore store;
	Computer c1("A", "A", "A", "A", 1, 1, 1, 1, true);
	Computer c2("B", "B", "B", "B", 2, 2, 2, 2, false);

	store.SetStoreName("Irshad Electronics");
	store.SetStoreAddress("Xirdalan");
	store.AddComputer(&c1);
	store.AddComputer(&c2);

	store.Print();
}