#include <iostream>
#include <fstream>
#include <string.h>



int main (int ac, char **av) {
  if(ac == 4)
  {
    int n=0;
    int pos=0;
    if(!strlen(av[2]))
      return 0;
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
      pos = line.find(av[2]);
      n = pos;
      while(n < (int)strlen(line.c_str()))
      {
        if(n == -1){
          outFile << line << std::endl;
          break ;
        }
        else{
          outFile <<line.substr(0,n);
          outFile <<av[3];
        }
        line = line.substr(n+strlen(av[2]),line.size());
        n= line.find(av[2]);
      }
    }  
    outFile.close();
    inFile.close();
  }
  return 0;
}
