#include "ras.h"
#include <iostream>

#include <smooth/pciio.h>

using namespace std;

int main()
{
	char rfn[1024];
	char pfn[1024];
	HBITMAP bmp;
	int im_id = 0;

	cout << "PCI filename: ";
	cin >> pfn;
	cout << "Loading file...";

	PCIIn	 pci = OpenPCIForInput(pfn);
	PCIIO	*pio = new PCIIO();

	ReadPCI(pci, *pio);

	bmp = (HBITMAP) pio->GetBitmap().GetSystemBitmap();

	ClosePCI(pci);

	delete pio;

	cout << "done.\n";
	cout << "Raster filename: ";
	cin >> rfn;
	cout << "Writing file...";

	SaveRAS(bmp, rfn);

	cout << "done.\n";

	return 0;
}
