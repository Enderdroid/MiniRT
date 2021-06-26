# MiniRT
My first RayTracer with miniLibX(OpenGL)

## Сборка
Сборка производится командой `make`

## Использование
Для запуска с использованием интерактивного инерфейса запустите исполняемый файл командой: `./minirt file.rt`
Где `file.rt` - файл конфигурации сцены

Если вы хотяте просто сохранить изображение сцены, то используйте флаг `--save`.
(Сохранение производится в формат [.bmp](https://ru.wikipedia.org/wiki/BMP))

Файл сцены должен соответствовать следующим условиям:
* Объявление разрешения.
* Объявление окружающего освещения.
* Одно или более объявление камер и освещения.
* Любое кол-во объектов.

### Файл сцены

Разрешение:	`R {width} {height}`
* Разрешение по оси OX.
* Разрешение по оси OY.

Окружающее освещение:	`A {ratio} {color}`
* Интенсивность окружающего освещения в диапазоне [0.0, 1.0].
* R,G,B цвета в диапазоне [0, 255].

Камера:	`c {position} {orientation} {FOV}`
* x,y,z координаты камеры.
* Вектор ориентации камеры x,y,z.
* FOV угол обзора камеры [0, 180].

Источник освещения:	`l {position} {ratio} {color}`
* x,y,z координаты источника освещения.
* Интенсивность освещения света в диапазоне [0.0, 1.0].
* R,G,B цвета в диапазоне [0, 255].

Сфера:	`sp {position} {size} {color}`
* x,y,z координаты центра сферы.
* Диаметр сферы.
* R,G,B цвета в диапазоне [0, 255].

Плоскость:	`pl {position} {orientation} {color}`
* x,y,z координаты точки на плоскости из которой выходит нормаль.
* Вектор ориентации плоскости x,y,z.
* R,G,B цвета в диапазоне [0, 255].

Квадрат:	`sq {position} {orientation} {side size} {color}`
* x,y,z координаты центра квадрата.
* Вектор ориентации квадрата x,y,z.
* Длина стороны квадрата.
* R,G,B цвета в диапазоне [0, 255].

Цилиндр:	`cy {position} {orientation} {diameter} {height} {color}`
* x,y,z координаты центра цилиндра.
* Вектор ориентации цилиндра x,y,z.
* Диаметр цилиндра.
* Высота цилиндра.
* R,G,B цвета в диапазоне [0, 255].

Треугольник:	`tr {first point} {second point} {third point} {color}`
* x,y,z координата вершины треугольника.
* x,y,z координата вершины треугольника.
* x,y,z координата вершины треугольника.
* R,G,B цвета в диапазоне [0, 255].

Пример файла сцены scene.rt:
```
R   420	420
A   0.2		255,255,255

l   0,2,0 0.3 255,101,0

c   -0.8,1.5,1  0.3,-0.5,-1 70
c   0,1,0       0,0,-1      70
c   0,5,5       0,-1,-1     70

sp	0,0,-2	2   255,0,255
tr	0,0,0	1,1,-1	-1,1,-1 255,255,0
pl	0,0,0	0,1,0   255,255,255
```

### Управление
Интерактивный режим носит своё название не просто так.
Все возможные интеракции перечислены ниже. 

**Выход**

Чтобы вайти из приложения используйте `q` или `Esc`.

**Камеры**

Для перемещения по камерам используйте клавиши `a`(предыдущая) и `d`(следующая).

## Изображения
![Alt-текст](https://github.com/Enderdroid/MiniRT/blob/main/imgs/dragon_0.png "Dragon")
![Alt-текст](https://github.com/Enderdroid/MiniRT/blob/main/imgs/sphere.png "Sphere")
![Alt-текст](https://github.com/Enderdroid/MiniRT/blob/main/imgs/origami_plane_5.png "Plane")
![Alt-текст](https://github.com/Enderdroid/MiniRT/blob/main/imgs/cat.png "Cat")
![Alt-текст](https://github.com/Enderdroid/MiniRT/blob/main/imgs/deer.png "Deer")
![Alt-текст](https://github.com/Enderdroid/MiniRT/blob/main/imgs/wolf3d_0.png "Wolf")
![Alt-текст](https://github.com/Enderdroid/MiniRT/blob/main/imgs/teapot_0.png "teapot")
![Alt-текст](https://github.com/Enderdroid/MiniRT/blob/main/imgs/sp_atom_0.png "More spheres")
