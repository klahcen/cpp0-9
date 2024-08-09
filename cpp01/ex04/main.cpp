#include <iostream>
#include <fstream>
#include <string.h>



int main (int ac, char **av) {
  if(ac == 4)
  {
    std::string file=av[1];
    std::string line;
    std::string outfile = file.append(".replace");
    std::ofstream outFile;
    std::ifstream inFile;
    inFile.open(av[1]);
    outFile.open(outfile.c_str());
    while (1)
    {
      if(!std::getline(inFile, line))
          break;
      int pos =line.find(av[2]);
      if(pos == -1)
        outFile << line << std::endl;
      else{
        std::cout <<strlen(av[3])<<"\n";
        outFile <<line.substr(0,pos);
        outFile <<av[3];
        outFile <<line.substr(pos+strlen(av[2]),line.size()) << std::endl;
        }
    }  
    outFile.close();
    inFile.close();
  }
  return 0;
}
