![UNTREF](http://untref.edu.ar/assets/img/logo_mobile.png)
# Ingeniería en Computación

## Algoritmos y Programación 3

### Árboles Binarios de Búsqueda

#### Grupo
  * Monti Matías - matiasmonti@hotmail.com
  * Araneda Alejandro - eloscurodeefeso@gmail.com

Trabajo Práctico entregado el:  
6 de Julio, 9 Hs.  
1ro Cuatrimestre de 2019

#### Docentes:
  * Aciti, Claudio Gustavo
  * Rodríguez, Martín Joel 

## Enunciado

> TP final parte 2: ejercicio integrador
> ---
> Desarrollar un sistema de créditos. Debe permitir:
> - Dar de alta y listar clientes
> - Buscar clientes por nombre
> - Buscar clientes por rango de edad
> - Cada cliente tiene una referencia que puede ser otro cliente
>
> Además cada cliente puede solicitar un crédito con determinado monto:
> - Dar de alta y listar créditos
> - Pagar crédito
> - Cancelar crédito
>
> El sistema debe poder soportar un gran listado de clientes y créditos. Los datos de clientes y créditos deben ser persistentes en archivos. Utilizar estructuras de datos para almacenar los listados. Decidir cuántas unidades se guardan en memoria y si se utiliza ordenamiento de los datos.
>
> Escribir un informe explicando la implementación de cada función y por qué se decidió hacerla de esa forma (un párrafo por cada función, no más). Explicar el modelo de negocio diseñado para resolver el problema (cómo se guardan los datos en los archivos, qué datos se guardan, etc.). Además detallar las dificultades que se enfrentaron en el desarrollo. Por qué se eligió una alternativa frente a la otra.
>
> El diseño del sistema y los modelos es libre. Utilizar la creatividad para que el manejo del sistema sea lo más práctico posible. Si los requerimientos planteados son cumplidos, el ejercicio está aprobado. Puede pasar que en situaciones en la que la cantidad de datos sea muy grande, el sistema sea inmanejable. En ese caso, detallar las limitaciones de la solución propuesta (si las limitaciones son reconocidas no se considera desaprobado el punto). Ideas no-obligatorias de implentar pero que podrían mejorar el sistema: utilizar paginado, poder elegir el cliente de un listado reducido, dar la posibilidad de hacer pagos parciales, generar clientes de prueba y créditos aleatorios de forma masiva, estadísticas de los clientes y créditos, etc.

## Indice General
1. [Introducción](#1-introducción)
2. [Recursos utilizados](#2-recursos-utilizados)
3. [Detalles de implementación](#3-detalles-de-implementación)
   1. [Diagrama de Clases](#3i-diagrama-de-clases)
   2. [Diagramas de Secuencia](#3ii-diagramas-de-secuencia)
      1. [Alta de Cliente](#3iia-alta-de-cliente)
      2. [Buscar Clientes](#3iib-buscar-clientes)
      3. [Listar Clientes](#3iic-listar-clientes)
      4. [Alta de Crédito](#3iid-alta-de-crédito)
      5. [Listar Créditos](#3iie-listar-créditos)
      6. [Operar Crédito](#3iif-operar-crédito)
   3. [Guía para Compilar](#3iii-guía-para-compilar)
   4. [Descripción de Archivos](#3iv-descripción-de-archivos)
4. [Conclusiones](#4-conclusiones)

[Referencias](#referencias)

## 1. Introducción

Ya hemos establecido en la Parte 1 de nuestro Trabajo Práctico<a name="cita-2" href="#ref-2"><sup>[2]</sup></a> la utilidad de los Árboles AVL<a name="cita-1" href="#ref-1"><sup>[1]</sup></a> como organizadores de grandes cantidades de información. El desafío en su utilización como índices de archivo, consiste en poder persistir la estructura arbolada con eficacia tanto en el tiempo como en el espacio.

En cuanto al espacio, es evidente que el almacenamiento ordenado de las claves es la solución más compacta. Pero así se pierde la estructura arbolada y por tanto sus propiedades de acceso logarítmico a sus hojas.

La siguiente solución natural incluye ya un procesamiento que introduce el factor tiempo: las claves se almacenan en pre-orden (raiz primero, rama menor después y rama mayor finalmente). Aquí, la comparación de las claves se hace necesaria para mantener la estructura.

Por la vertiente contraria, al asumir que el árbol es completo, o introduciendo claves nulas se podría reconstruir la estructura del árbol sin necesidad de conocer la función de orden del conjunto, con el consecuente costo en espacio desaprovechado.

La solución intermedia habitual y que nosotros implementaremos, es la de agregar un marcador a la clave indicando si es una hoja o si tiene hijos y cuales. Esto reduce el procesamiento y no es necesario conocer la funcion de orden, y no desaprovecha espacio de almacenamiento.

## 2. Recursos utilizados

Para nuestro desarrollo hemos utilizida el Entorno de Desarrollo Integrado (IDE) Code::Blocks<a name="cita-3" href="#ref-3"><sup>[3]</sup></a>
para el sistema operativo Windows y con un compilador portado del GCC de GNU aportado por el proyecto de entorno de desarrollo MinGW<a name="cita-4" href="#ref-4"><sup>[4]</sup></a>. 

En cuanto al lenguage C propiamente, hemos utilizado sólo las características y sintaxis del ANSI C89/ ISO C90 adhiriendo en lo posible al estilo de codificación del kernel de Linux<a name="cita-5" href="#ref-5"><sup>[5]</sup></a> 
y su guía para la documentación<a name="cita-6" href="#ref-6"><sup>[6]</sup></a>. 

## 3. Detalles de implementación

### 3.i. Diagrama de Clases

![Diagrama de Clases](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/MatiasMonti/TP-final-parte-2/master/diagrama.puml)

### 3.ii. Diagramas de Secuencia

#### 3.ii.a Alta de Cliente 

![Diagrama de Secuencia: Alta de Clientes](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/MatiasMonti/TP-final-parte-2/master/altacliente.puml)

#### 3.ii.b Buscar Clientes

![Diagrama de Secuencia: Buscar Clientes](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/MatiasMonti/TP-final-parte-2/master/buscarcliente.puml)

#### 3.ii.c Listar Clientes

![Diagrama de Secuencia: Listar Clientes](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/MatiasMonti/TP-final-parte-2/master/listarclientes.puml)

#### 3.ii.d Alta de Crédito

![Diagrama de Secuencia: Alta de Crédito](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/MatiasMonti/TP-final-parte-2/master/altacredito.puml)

#### 3.ii.e Listar Créditos

![Diagrama de Secuencia: Listar Créditos](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/MatiasMonti/TP-final-parte-2/master/listarcreditos.puml)

#### 3.ii.f Operar Crédito

![Diagrama de Secuencia: Operar Crédito](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/MatiasMonti/TP-final-parte-2/master/operarcredito.puml)

### 3.iii. Guía para Compilar

Para compilar y correr los test en Code::Blocks abrir el proyecto `tp2.cbp` y seleccionar en la lista de "build target" la configuración `"Debug"` y presionar <kbd>F9</kbd>:

![Debug buil target](Debug.png)

Para compilar y correr la aplicación en Code::Blocks abrir el proyecto `tp2.cbp` y seleccionar en la lista de "build target" la configuración `"Release"` y presionar <kbd>F9</kbd>:

![Release buil target](Release.png)

### 3.iv. Descripción de Archivos

#### Archivo [`aplicacion.c`](aplicacion.c)

El archivo `aplicacion.c` contiene la implementación de la aplicación, funciones y módulos auxiliares y la interfaz de usuario. 

#### Archivo [`aplicacion.h`](aplicacion.h)

El archivo `aplicacion.h` contiene la interfaz de la aplicación con las funciones y módulos auxiliares.

#### Archivo [`claves.c`](claves.c)
El archivo `claves.c` contiene la implementacion del TAD claves con sus metodos que permiten comparar claves entre si y persistirlas

#### Archivo [`claves.h`](claves.h)
El archivo `claves.h` contiene la interfaz del TAD claves con la definicion de sus metodos.

#### Archivo [`cliente.c`](cliente.c)
El archivo `cliente.c` contiene la implementacion del TAD cliente con sus metodos que permiten crear y modificar la informacion de los clientes, tambien se encarga de su persistencia y de mostrar sus datos en pantalla.

#### Archivo [`cliente.h`](cliente.h)
El archivo `cliente.h` contiene la interfaz del TAD cliente con la definicion de sus metodos.

#### Archivo [`credito.c`](credito.c)
El archivo `credito.c` contiene la implementacion del TAD credito con sus metodos que permiten crear, borrar y modificar los creditos que seran de cada cliente.

#### Archivo [`credito.h`](credito.h)
El archivo `credito.h` contiene la interfaz del TAD credito con la definicion de sus metodos.

#### Archivo [`indice.c`](indice.c)
El archivo `indice.c` contiene la implementacion del TAD indice el cual será utilizado para representar el Indice implementado como
un Árbol AVL. Tambien contiene la implementacion del TAD iterador utilizado para representar el Iterador del Indice implementado como Árbol AVL que permiten recorrer el iterador.

#### Archivo [`indice.h`](indice.h)
El archivo `indice.h` contiene la interfaz del TAD indice y el TAD Iterador con la definicion de sus metodos.

#### Carpeta [`avl`](/avl)
La carpeta contiene la interfaz e implementacion (archivos `avl.h` y `avl.c`) del Árbol AVL<a name="cita-1" href="#ref-1"><sup>[1]</sup></a> correspondiente al Trabajo Practico N°2 Primera Parte.

#### Carpeta [`test`](/test)
La carpeta contiene el punto de ingreso `test.c` a todos los test del proyecto, así como la interfaz de los test unitarios para enlazarlos (archivos `test_cliente.h`, `test_credito.h`, etc.) y sus implementaciones.

## Referencias

<a name="ref-1" href="#cita-1"><sup>[1]</sup></a> Adelson-Velsky, Georgy; Landis, Evgenii (1962). "An algorithm for the organization of information". Proceedings of the USSR Academy of Sciences (in Russian). 146: 263–266

<a name="ref-2" href="#cita-2"><sup>[2]</sup></a> Monti, Matias; Araneda, Alejandro (2019) "Trabajo Práctico N° 2 de Algoritmos y Programación 3 para la carrera de Ing. en Computación de la UNTREF". recuperado de https://github.com/HeraclitoDeEfeso/ayp3-tp2

<a name="ref-3" href="#cita-3"><sup>[3]</sup></a> "The open source, cross platform, free C, C++ and Fortran IDE", recuperado de www.codeblocks.org

<a name="ref-4" href="#cita-4"><sup>[4]</sup></a> "Minimalist GNU for Windows", recuperado de www.mingw.org

<a name="ref-5" href="#cita-5"><sup>[5]</sup></a> "Linux kernel coding style", recuperado de http://www.kernel.org/doc/html/v4.10/process/coding-style.html

<a name="ref-6" href="#cita-6"><sup>[6]</sup></a> "Writing kernel-doc comments", recuperado de http://www.kernel.org/doc/html/v4.10/doc-guide/kernel-doc.html
