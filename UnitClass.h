//---------------------------------------------------------------------------
#include <vcl.h>

#ifndef UnitClassH
#define UnitClassH
 #include "math.h"
#include "UnitMain.h"


        // Ввод параметра int
        void input (String Vvedite, int &par)
        {
                String s;
                InputQuery("Ввод параметров", Vvedite, s);
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

  // Копиурем
  PicStart->Canvas->CopyRect(PicResult->ClientRect,PicResult->Canvas,PicResult->ClientRect);

  int w=PicStart->Width;
  int h=PicStart->Height;


  double a=(double)10/180.0*M_PI; // на 30 градусов

  // Очищаем новую картинку
  PicResult->Canvas->FillRect(PicResult->ClientRect);


  // Проходим по всем точкам
  for (int i=0; i<h; i++)
    for (int j=0; j<w; j++)
      {


        // Поворот координат
        int x =w+  (j-w)*cos(a)-(i-h)*sin(a);
        int y =h+  (j-w)*sin(a)+(i-h)*cos(a);



        // Ставим соответствующую точку на новые координаты
        PicResult->Canvas->Pixels [y][x]=PicStart->Canvas->Pixels [i][j];
       
      };

    delete(PicStart);
};






//Создание базового абстрактного класса с виртуальными функциями
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
	//Виртуальная функция для рисования фигуры
	virtual void draw(TImage*)
	{ }
	//Виртуальная функция для изменения фигуры
	virtual void change(TImage*)
	{ }
	//Виртуальная функция для перемещения фигуры
	virtual void move(TImage*)
	{ }
	//Виртуальная функция для вращения фигуры
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
                input("Введите координату Х центра окружности: ",xCo);
		input("Введите координату У центра окружности: ",yCo);
		input("Введите радиус окружности: ",radius);


	}
	circle(int x, int y)
	{
		xCo = x;
		yCo = y;
		input("Введите радиус окружности: ",radius);


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
		
		input("Введите новый радиус окружности: ",radius);
		draw(img);
                ShowMessage("Круг изменён");  
	}
	void move(TImage* img)
	{
		
                input("Введите новую координату Х центра окружности: ",xCo);
		input("Введите новую координату У центра окружности: ",yCo);

                draw(img);
		ShowMessage("Круг перемещён");
	}
	void rotation(TImage* img)
	{
                draw(img);
                Povorot(img);
		ShowMessage("Круг вращается");
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
                input("Введите координату Х верхнего левого угла: ",xCo);
		input("Введите координату У цверхнего левого угла: ",yCo);
		input("Введите длину стороны: ",width);
        }

	square(int x, int y)
	{
		xCo = x;
		yCo = y;
		input("Введите длину стороны: ",width);

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
		
                input("Введите новую координату Х верхнего левого угла: ",xCo);
		input("Введите новую координату У цверхнего левого угла: ",yCo);
		
                draw(img);
		ShowMessage("Квадрат перемещён");
	}

	void change(TImage* img)
	{
		
		input("Введите новую длину стороны: ",width);
		draw(img);
		ShowMessage("Квадрат изменён");
	}
	void rotation(TImage* img)
	{
                draw(img);
                Povorot(img);
		ShowMessage("Квадрат вращается");

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
		input("Введите высоту: ",height);
	}


	rect(int x, int y) : square(x,y)
	{
		input("Введите высоту: ", height);
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
		
		input("Введите новую координату Х: ", xCo);
		input("Введите новую координату У: ",yCo);

                draw(img);
		ShowMessage("Прямоугольник перемещён");

	}
	void change(TImage* img)
	{
		
		input("Введите новую высоту прямоугольника:", height);
		input("Введите новую ширину прямоугольника:", width);

		draw(img);
		ShowMessage("Прямоугольник изменён");
	}
	void rotation(TImage* img)
	{
                draw(img);
                Povorot(img);
		ShowMessage("Прямоугольник вращается");

	}
};

























//---------------------------------------------------------------------------
#endif
