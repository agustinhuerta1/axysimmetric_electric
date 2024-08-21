## Modelo axisimétrico

## Descripción

Estudio de modelo Darwin en una geometría axisimétrica para obtención de la respuesta dinámica de una bobina de un transformador. Se realiza un esquema numérico bajo el método de elementos finitos en el programa FreFEM, uno de bastantes solvers _open source_.  Las consideraciones a tener en cuenta en los cálculos es que solo considera excitación en una vuelta,  que admite enmallados que tienen la suficiente precisión en los conductores, esto se debe a que se condiciona de mejor forma la matriz generada por el ensamble, y que los recursos entregados están pensados fuera del marco del funcionamiento del software.

## Índice

- [Instalación](#instalación)
- [Uso](#uso)
- [Documentación](#documentación)
- [Soporte](#soporte)
- [Créditos](#créditos)

## Instrucciones de instalación

Podemos realizar la instalación de estos dos programas con las instrucciones de sus páginas respectivas,

1. FreeFEM https://github.com/FreeFem/FreeFem-sources/releases
2. Paraview https://www.paraview.org/download/

Ambos poseen un instalador. Se dispone ambos instaladores en la carpeta Onedrive de la documentación. En caso de requerir instalación del paquete de librerías PETsc se recomienda realizarlo en una maquina virtual con sistema con Ubuntu instalado, todo esto siguiendo las indicaciones de [https://doc.freefem.org/introduction/installation.html](url).

### Uso


El modo de funcionamiento de FreeFem puede ser desarrollado a mano, solo seleccionando el script, o por consola. Por consola debemos dar la linea de comando

`C:\...\>FreeFem++ nombre_de_script.edp`

Consideraciones a tener en cuenta en el funcionamiento de FreeFEM.

Ejemplo de una simulación:

1. Realizamos el comando adecuado por cmd

![1](https://github.com/jportal93/rhona/assets/70775080/c483649f-8547-40ab-a100-904ae64ab018)

2. Debería desplegar información de los pasos

![2](https://github.com/jportal93/rhona/assets/70775080/b9432076-a246-4902-a0f3-fa701651c90e)

3. Luego de la finalización los resultados pueden ser visto en Paraview

![3](https://github.com/jportal93/rhona/assets/70775080/facd3199-f3cb-4118-9150-b0b92ad521d7)

4. El script malla_estructurada/malla_estructurada2x2.edp entrega los .vtk del campo eléctrico, campo magnético y potencial eléctrico.

![4](https://github.com/jportal93/rhona/assets/70775080/84f6a777-4f0d-498b-b296-aec3f1549095)

## Documentación

1. Enlaces a la documentación o secciones específicas en carpeta: https://usmcl.sharepoint.com/:f:/s/GestindeequipodeDesarrollo/EiFX4V8a-JRDnYpNirg6C84BI_arpzh3ee5XB9SFwfw-0A?email=agustin.huerta%40usmcl.onmicrosoft.com&e=CIXMbp
2. Se encuentra documentación adicional: Implementación numérica.pdf.

## Soporte

Agustín Huerta Soto agustin.huerta@sansano.sum.cl

## Créditos

Autores y colaboradores.
