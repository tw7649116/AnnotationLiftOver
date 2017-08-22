/*
 * =====================================================================================
 *
 *       Filename:  testRunExonerate.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/23/2017 21:22:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
/*************************************************************************




 ************************************************************************/

#include<iostream>
#include "reAnnotationAndMsa.h"
int main(){
    std::string query="ATGGCTGATAGGATCAAAGGTCCATGGAGTCCTGAAGAAGACGAGCAGCTTCGTAGGCTTGTTGTTAAATACGGTCCAAGAAACTGGACAGTGATTAGCAAATCTATTCCCGGTAGATCGGGGAAATCGTGTCGTTTACGGTGGTGCAACCAGCTTTCGCCGCAAGTTGAGCATCGGCCGTTTTCGGCTGAGGAAGACGAGACGATCGCACGTGCTCACGCTCAGTTCGGTAATAAATGGGCGACGATTGCTCGTCTTCTCAACGGTCGTACGGACAACGCCGTGAAGAATCACTGGAACTCGACGCTCAAGAGGAAATGCGGCGGTTACGACCATCGGGGTTACGATGGTTCGGAGGATCATCGGCCGGTTAAGAGATCGGTGAGTGCGGGATCTCCACCTGTTGTTACTGGGCTTTACATGAGCCCAGGAAGCCCAACTGGATCTGATGTCAGTGATTCAAGTACTATCCCGATATTACCTTCCGTTGAGCTTTTCAAGCCTGTGCCTAGACCTGGTGCTGTTGTGCTACCGCTTCCTATCGAAACGTCGTCTTCTTCCGATGATCCACCGACTTCGTTAAGCTTGTCACTTCCTGGTGCCGACGTAAGCGAGGAGTCAAACCGTAGCCACGAGTCAACGAATATCAACAACACCACTTCGAGCCGCCACAACCACAACAATACGGTGTCGTTTATGCCGTTTAGTGGTGGGTTTAGAGGTGCGATTGAGGAAATGGGGAAGTCTTTTCCCGGTAACGGAGGCGAGTTTATGGCGGTGGTGCAAGAGATGATTAAGGCGGAAGTGAGGAGTTACATGACGGAGATGCAACGGAACAATGGTGGCGGATTCGTCGGAGGATTCATTGATAATGGCATGATTCCGATGAGTCAAATTGGAGTTGGGAGAATCGAGTAG";
    std::string target="CCTATCTTTTGTTAACCGCACATTTTACATCACGTTTCCTAAACCGAACATTAATATCTAACCATTTTTATACATTCACTTAATATCGCTCACACGGTTCTTTGTCAATCCCATTTTAATCCAGCTTCGTTTCAAATTATTGAGGTTTAGATCTTTTTATGATCATAGAGCAACTATATATAGATTTAGTATTGTCAATTTGTCATGCACTGTTATATGCATGAATTAGGTGTTTGTGTGTTGTTTAGTAATTAATTATACCTTCTTAGTGACAATTTGTTTTCTTTATTAGTAATGAAATTTGTGGTCAATAATTTTGATTAGTTTTCAACCCGGAAAATCGGTTATATGTAAAGTAGATATTATCATAAAGTTTTTATGTGAAGTGCTATACAGCCTGGCTTCGCTATTCTAAAGTCAGACTAAACATAAAAATAAATAAAAACTGTCCTTACCCAAACCTAACCGTTATCATCTTTTTATTTTTTTCTTCAGATATTTCTTTTTAATTTTTATTTCCCCTATAAAAAAATTTAAATTCACCTCAAATTGTGCGAATATTATCATGGCTTTGCTAGTTGGGTTTCGTGATTTTGTCTCTTTAACTTCTTACTTTCGCCACGCGCTTAAATGGCGCGTGTACTCACAAACTCATACTTTGAGACTCGACTGATCTCCACGCTCAACTATACGAAATTGCTGATCTTGAACAAAATTATTACGAAAACGACAAAAAAGACACATCGACGTAGTCAGGCTTCGACGCGTGTCCACTTACAGCTGTACCGCAAACTTTGAAAAACCGCTTGCGTGGAAGAAGCGTTGCCCATGACTTCTCCACCGTCTTAACCGGTTTCCGGTTATCCTCCTCTCTTAAATCTCTGTATAAATAATTTTGTCCTCTCTTTAGTTTCTCGAACTTGTTTTTGGTTCATCTCTCAAAACCAAAATCACTAAAGAGGAGAAGATTGCTAAAGTTTGATAAAACATTCCAAAATCAATGGCTGATAGGATCAAAGGTCCATGGAGTCCTGAAGAAGACGAGCAGCTTCGTAGGCTTGTTGTTAAATACGGTCCAAGAAACTGGACAGTGATTAGCAAATCTATTCCCGGTAGATCGGGGAAATCGTGTCGTTTACGGTGGTGCAACCAGCTTTCGCCGCAAGTTGAGCATCGGCCGTTTTCGGCTGAGGAAGACGAGACGATCGCACGTGCTCACGCTCAGTTCGGTAATAAATGGGCGACGATTGCTCGTCTTCTCAACGGTCGTACGGACAACGCCGTGAAGAATCACTGGAACTCGACGCTCAAGAGGAAATGCGGCGGTTACGACCATCGGGGTTACGATGGTTCGGAGGATCATCGGCCGGTTAAGAGATCGGTGAGTGCGGGATCTCCACCTGTTGTTACTGGGCTTTACATGAGCCCAGGAAGCCCAACTGGATCTGATGTCAGTGATTCAAGTACTATCCCGATATTACCTTCCGTTGAGCTTTTCAAGCCTGTGCCTAGACCTGGTGCTGTTGTGCTACCGCTTCCTATCGAAACGTCGTCTTCTTCCGATGATCCACCGACTTCGTTAAGCTTGTCACTTCCTGGTGCCGACGTAAGCGAGGAGTCAAACCGTAGCCACGAGTCAACGAATATCAACAACACCACTTCGAGCCGCCACAACCACAACAATACGGTGTCGTTTATGCCGTTTAGTGGTGGGTTTAGAGGTGCGATTGAGGAAATGGGGAAGTCTTTTCCCGGTAACGGAGGCGAGTTTATGGCGGTGGTGCAAGAGATGATTAAGGCGGAAGTGAGGAGTTACATGACGGAGATGCAACGGAACAATGGTGGCGGATTCGTCGGAGGATTCATTGATAATGGCATGATTCCGATGAGTCAAATTGGAGTTGGGAGAATCGAGTAGACAAAGTGAGATTATTAGGAAACTGTTTAAATTGGAGAAGAAGAAAAATGCTCTGTTTTTTTCTCCTTTGGATTAGGCTTAAGAATTTTGGGTTTTAAGGAAATGTATAGAGGAAATCGAGTGAACAAAGCTCGAGAGCTGGGGACGTAGTGACGAAGACGAAGATCAAATTTCTCTTAAGCTATTCAGGAAAATAAAATAAATTTTTATTTATAACTACGCTTAATGATGATAATAGATCAAATTAATACACAAAGTATCACAAAGTGAAAGATAAATGATCCAGTTAAAGAACAAGTTTGTCGAGGATTGGTAAAGACTTGCATTTGGCAACTAAAGGCACAGATTTGGGCATGGTAAGACCCTTTCCTTCCGACATGTCAACGGCAACGTCATTGTCTCTCTCCCAATCGAAACACTGGATCAATGAGCCTAAAGCTAAGCTCAGTACTAGTTGGGCCAGGCCCATACCAGGACATGCTCTCCTACCGATTCCGAAAGGCAGAAACTTACCACGATGGGTCTCTGATTCAAACCTCTCTGGTTTGAAAGTTTCTGGGTCATCCCATACATTTGGGTCTCTCTGAATAGCCCACGCATTGATAAATAGCCAGGTGCGACGTGGAATGTCAAATCCAGCGACTTCACAGTCAGTGGATGAAGCGTGTGGGACAAGTAAGGGCGCCGCCGGAAACAAACGAAGAGTCTCAGAGATCACATTGTTGAGATAGGGACACTTGCCAGTATCTGATTCCTCAAACACACGCCCTTCTTTCGAAACCTCGTTTAGTTCCGTTTTGAGTTTCCTTAAAACTTCCGGATGATTTAGAAGGTTAGCCATAGCCCACTCCAACGTCACTGCGGTTGTGTCCGTTCCAGCAAGCAACATCACCTGCAATGAATCCTTTGAATCTTTGATGAATCAATCTTGATCACTCCTATTAACGATTCAAAATTATAGGAATTAAAAACTCATGTACCTGTACGAGCCCTTTGATGA";
    runExonerate(query, target);
    return 0;
}

