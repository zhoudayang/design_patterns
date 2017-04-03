#pragma once

#include <iostream>

using std::cout;
using std::endl;

class CSyntaxParser
{
  public:
    void SyntaxParser()
    {
      cout << "syntax parse" << endl;
    }
};

class CGenMidCode
{
  public:
    void GenMidCode()
    {
      cout << "generate midlle code" << endl;
    }
};

class CGenAssemblyCode
{
  public:
    void GenAssemblyCode()
    {
      cout << "generate assembly code" << endl;
    }
};

class CLinkSystem
{
  public:
    void LinkSystem()
    {
      cout << "link system" << endl;
    }
};


// 编译器的编译实际上是将上述行为组合起来，暴露给用户使用
class Facade
{
  public:
    void Compile()
    {
      CSyntaxParser parser;
      CGenMidCode genMidCode;
      CGenAssemblyCode genAssemblyCode;
      CLinkSystem linkSystem;
      parser.SyntaxParser();
      genMidCode.GenMidCode();
      genAssemblyCode.GenAssemblyCode();
      linkSystem.LinkSystem();
    }
};







