#include "categorizer.hpp"
using namespace std;

void PrintHistogram(ostream& out,
                    unsigned int *histogram,
                    unsigned int len,
                    int width,
                    int height)
{    
    out << "Building histogram for graphic file" << endl;
    out << "Width: " << width << "\t Height: " << height << endl;
    for(unsigned int j = 0; j < len; j++)
    {
        out << "[" << j << "] ";
        for(unsigned int c = 0; c < histogram[j]; c++)
            out << "|";
        out << endl;
    }
    out << "End of file " << endl << endl;
}

void ProcessFile(std::fstream *file, unsigned int* histogram, unsigned int len)
{

    int width, height;
    width = 0;
    height = 0;
    std::string MagicNumber;

    *file >> MagicNumber;
    if(MagicNumber != "P5") return;

    cout << "PGM header detected" << endl;

    *file >> width;
    cout << "Width: " << width <<  endl;

    *file >> height;
    cout << "Height: " << width <<  endl;

    for(unsigned int d = 0; d < len; ++d)histogram[d] = 0;

    while(!file->eof())
        histogram[static_cast<unsigned char>(file->get())]++;

    PrintHistogram(cout, histogram, len, width, height);

    ofstream out("histogram.txt");
    PrintHistogram(out, histogram, len, width, height);
    out.close();
}

int main(int argc, char** args)
{
    fstream *f = new fstream();
    unsigned int histogram[256];

    if(argc == 1)
    {
        cout << "Please specify input file(s)!" << endl;
        return 1;
    }
    for(int i = 1; i < argc; i++)
    {
        f->open(args[i], ios::binary|ios::in);
        if(!f->is_open())
        {
            cout << "File: " << args[i] << " is not accessible!" << endl;
            continue;
        }
        cout << "File " << args[i] << " opened" << endl;
        ProcessFile(f, histogram, 256);
        f->close();
    }
    delete f;
    return 0;
}
