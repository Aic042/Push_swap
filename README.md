## Parsing (70% completado)

### 📂 Ubicación
Todo el código relacionado al parseo se encuentra en la carpeta `parsing/`.

### 📋 Pendientes por mejorar
- Aún falta finalizar completamente el parser.
- Todos los mensajes de error actualmente son iguales. Es necesario hacerlos más específicos para facilitar el debugging.
- No se están capturando errores importantes, como cuando se pasa un número mayor al límite que puede almacenar un `int`.
- Algunas funciones están retornando `0` incluso cuando hay errores evidentes en la entrada.

### 🛠️ Compilación para pruebas
Puedes compilar el parser con este comando:
```bash
gcc parsing/*.c push_swap.h libft/libft.a -o parse_test
