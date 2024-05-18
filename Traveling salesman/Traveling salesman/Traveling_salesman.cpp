// Traveling salesman.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "traveling_salesman.h"
#include "freeglut.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
	system("chcp 1251");

	glutInit(&argc, argv); // Инициализация GLUT с аргументами командной строки
	graph = createGraph(); // Создание карты для задачи коммивояжера
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);  // Установка режима отображения для OpenGL

	glutInitWindowSize(1350, 730); // Задание размеров окна
	glutCreateWindow("Коммивояжер");  // Создание окна с названием "Коммивояжер"
	WinWeight = glutGet(GLUT_WINDOW_WIDTH); // Получение ширины окна
	WinHeight = glutGet(GLUT_WINDOW_HEIGHT); // Получение высоты окна

	//loadTexture();

	glutDisplayFunc(display); // Регистрация функции отображения
	glutReshapeFunc(reshape); // Регистрация функции изменения размеров окна
	glutMouseFunc(mouseClick); // Регистрация функции обработки событий мыши
	glutMainLoop(); // Запуск основного цикла GLUT

	return 0;
}



