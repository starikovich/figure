//---------------------------------------------------------------------------
#include <vcl.h>

#ifndef UnitClassH
#define UnitClassH
 #include "math.h"
#include "UnitMain.h"


        // ���� ��������� int
        void input (String Vvedite, int &par)
        {
                String s;
                InputQuery("���� ����������", Vvedite, s);
                par=StrToInt(s);

        };


void Povorot (TImage* PicResult)
{
  TImage* PicStart=new TImage(NULL);
  PicStart->Visible=false;
  PicStart->Name="PicStart";
  PicStart->Top=0;
  PicStart->Left=0;
  PicStart->Width=PicResult->Width;
  PicStart->Height=PicResult->Height;
  PicStart->Parent=NULL;

  // ��������
  PicStart->Canvas->CopyRect(PicResult->ClientRect,PicResult->Canvas,PicResult->ClientRect);

  int w=PicStart->Width;
  int h=PicStart->Height;


  double a=(double)10/180.0*M_PI; // �� 30 ��������

  // ������� ����� ��������
  PicResult->Canvas->FillRect(PicResult->ClientRect);


  // �������� �� ���� ������
  for (int i=0; i<h; i++)
    for (int j=0; j<w; j++)
      {


        // ������� ���������
        int x =w+  (j-w)*cos(a)-(i-h)*sin(a);
        int y =h+  (j-w)*sin(a)+(i-h)*cos(a);



        // ������ ��������������� ����� �� ����� ����������
        PicResult->Canvas->Pixels [y][x]=PicStart->Canvas->Pixels [i][j];
       
      };

    delete(PicStart);
};






//�������� �������� ������������ ������ � ������������ ���������
class shape
{
public:
	int xCo, yCo;
public:
	int getX()
	{
		return xCo;
	}
	int getY()
	{
		return yCo;
	}
	//����������� ������� ��� ��������� ������
	virtual void draw(TImage*)
	{ }
	//����������� ������� ��� ��������� ������
	virtual void change(TImage*)
	{ }
	//����������� ������� ��� ����������� ������
	virtual void move(TImage*)
	{ }
	//����������� ������� ��� �������� ������
	virtual void  rotation(TImage*)
	{ }


};







//////////////////////////////////////




class circle : public shape
{
private:
	int radius;
public:
	circle()
	{
                input("������� ���������� � ������ ����������: ",xCo);
		input("������� ���������� � ������ ����������: ",yCo);
		input("������� ������ ����������: ",radius);


	}
	circle(int x, int y)
	{
		xCo = x;
		yCo = y;
		input("������� ������ ����������: ",radius);


	}
	void draw(TImage* img)
	{
                img->Canvas->Brush->Style=bsSolid;
                img->Canvas->Brush->Color=clWhite;
                img->Canvas->FillRect(img->ClientRect);

                img->Canvas->Pen->Style=psSolid;
                img->Canvas->Pen->Color=clBlack;

                img->Canvas->Ellipse(xCo-radius,yCo-radius,xCo+radius,yCo+radius);

	}
	void change(TImage* img)
	{
		
		input("������� ����� ������ ����������: ",radius);
		draw(img);
                ShowMessage("���� ������");  
	}
	void move(TImage* img)
	{
		
                input("������� ����� ���������� � ������ ����������: ",xCo);
		input("������� ����� ���������� � ������ ����������: ",yCo);

                draw(img);
		ShowMessage("���� ���������");
	}
	void rotation(TImage* img)
	{
                draw(img);
                Povorot(img);
		ShowMessage("���� ���������");
	}
};







//////////////////////////////////////

class square : public shape
{
protected:
	int width;
public:
	square()
	{
                input("������� ���������� � �������� ������ ����: ",xCo);
		input("������� ���������� � ��������� ������ ����: ",yCo);
		input("������� ����� �������: ",width);
        }

	square(int x, int y)
	{
		xCo = x;
		yCo = y;
		input("������� ����� �������: ",width);

	}

	void draw(TImage* img)
	{
                img->Canvas->Brush->Style=bsSolid;
                img->Canvas->Brush->Color=clWhite;
                img->Canvas->FillRect(img->ClientRect);

                img->Canvas->Pen->Style=psSolid;
                img->Canvas->Pen->Color=clBlack;

                img->Canvas->Rectangle(xCo,yCo,xCo+width,yCo+width);




	}

	void move(TImage* img)
	{
		
                input("������� ����� ���������� � �������� ������ ����: ",xCo);
		input("������� ����� ���������� � ��������� ������ ����: ",yCo);
		
                draw(img);
		ShowMessage("������� ���������");
	}

	void change(TImage* img)
	{
		
		input("������� ����� ����� �������: ",width);
		draw(img);
		ShowMessage("������� ������");
	}
	void rotation(TImage* img)
	{
                draw(img);
                Povorot(img);
		ShowMessage("������� ���������");

	}
};






///////////////////////////////////////////////////
class rect : public square
{
protected:
	int height;
public:

	rect() :  square()
	{
		input("������� ������: ",height);
	}


	rect(int x, int y) : square(x,y)
	{
		input("������� ������: ", height);
	}

	virtual void  draw(TImage* img)
	{
                img->Canvas->Brush->Style=bsSolid;
                img->Canvas->Brush->Color=clWhite;
                img->Canvas->FillRect(img->ClientRect);

                img->Canvas->Pen->Style=psSolid;
                img->Canvas->Pen->Color=clBlack;

                img->Canvas->Rectangle(xCo,yCo,xCo+width,yCo+height);



	}
	virtual void  move(TImage* img)
	{
		
		input("������� ����� ���������� �: ", xCo);
		input("������� ����� ���������� �: ",yCo);

                draw(img);
		ShowMessage("������������� ���������");

	}
	void change(TImage* img)
	{
		
		input("������� ����� ������ ��������������:", height);
		input("������� ����� ������ ��������������:", width);

		draw(img);
		ShowMessage("������������� ������");
	}
	void rotation(TImage* img)
	{
                draw(img);
                Povorot(img);
		ShowMessage("������������� ���������");

	}
};

























//---------------------------------------------------------------------------
#endif
