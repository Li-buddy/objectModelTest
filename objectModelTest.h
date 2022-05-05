// testForObjectModel.h : Include file for standard system include files,
// or project specific include files.
#ifndef OBJECT_MODEL_H_
#define OBJECT_MODEL_H_

#include <iostream>
using namespace std;

namespace just_data
{
  class furniture
  {
  public:    
    int m_furWeight = 10;
  };

  class sofa : public furniture
  {
  public:
    int m_sofaWeight;
  };

  class bed : public furniture
  {
  public:
    int m_bedWeight;
  };

  class sofabed : public sofa, public bed
  {
  public:
    int m_sofabedWeight;
  };
}

namespace virtual_function
{
  class furniture
  {
  public:
    virtual void furFunc()
    {
      cout << "furinture::furFunc" << endl;
    }
    virtual void furFunc2()
    {
      cout << "furinture::furFunc2" << endl;
    }
    int m_furWeight = 10;
  };

  class sofa : public furniture
  {
  public:
    virtual void sofaFunc()
    {
      cout << "sofa::sofaFunc" << endl;
    }
    int m_sofaWeight;
  };

  class bed : public furniture
  {
  public:
    virtual void bedFunc()
    {
      cout << "bed::bedFunc" << endl;
    }
    int m_bedWeight;
  };
  
  class sofabed : public sofa, public bed
  {
  public:
    virtual void sofabedFunc()
    {
      cout << "sofabed::sofabedFunc" << endl;
    }
    int m_sofabedWeight;
  };
}

namespace virtual_inheritance
{

  class furniture
  {
  public:
    int m_furWeight = 10;
  };

  class bed :virtual public furniture
  {
  public:
    int m_bedWeight;
  };

  class sofa : virtual public furniture
  {
  public:
    int m_sofaWeight;
  };

  class sofabed : public sofa, public bed
  {
  public:
    int m_sofabedWeight;
  };

}

namespace virtual_inheritance_function
{
  class furniture
  {
  public:
    virtual void furFunc()
    {
      cout << "furinture::furFunc" << endl;
    }
    virtual void furFunc2()
    {
      cout << "furinture::furFunc2" << endl;
    }
    int m_furWeight = 10;
  };

  class bed :virtual public furniture
  {
  public:
    virtual void bedFunc()
    {
      cout << "bed::bedFunc" << endl;
    }
    int m_bedWeight;
  };

  class sofa : virtual public furniture
  {
  public:
    virtual void sofaFunc()
    {
      cout << "sofa::sofaFunc" << endl;
    }
    int m_sofaWeight;
  };

  class sofabed : public sofa, public bed
  {
  public:
    virtual void sofabedFunc()
    {
      cout << "sofabed::sofabedFunc" << endl;
    }
    int m_sofabedWeight;
  };
}

#endif //OBJECT_MODEL_H_