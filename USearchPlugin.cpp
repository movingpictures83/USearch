#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "USearchPlugin.h"

void USearchPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile, std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void USearchPlugin::run() {}

void USearchPlugin::output(std::string file) {
//-cluster_fast HMP_MOCK.v35.fasta -id 0.9 -centroids nr.fasta
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "usearch";
myCommand += " -cluster_fast ";
myCommand += parameters["sequences"];
myCommand += " -id ";
myCommand += parameters["id"];
myCommand += " -centroids ";
myCommand += outputfile;
std::cout<<myCommand<<std::endl;
 system(myCommand.c_str());
}

PluginProxy<USearchPlugin> USearchPluginProxy = PluginProxy<USearchPlugin>("USearch", PluginManager::getInstance());
