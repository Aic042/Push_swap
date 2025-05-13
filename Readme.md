/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Readme.md                                      	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:04:52 by root              #+#    #+#             */
/*   Updated: 2025/05/12 13:14:05 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


Empezamos con el main.
Declaramos los stacks con t_stack (a y b)
Luego el array de numeros (int *nums)
Despues, int count que ya lo usaremos mas tarde.


________Primera Etapa(Parsing)_________
	if (argc < 2)
		return (0);
Checkeamos que los argumentos no sean menos de 2 que habrian de ser el nombre del 
programa y luego la cadena de numeros.

	if (!parse_args(argc, argv, &nums, &count))
		return (1);

Llamamos a la funcion parse_args que se encarga de parsear los argumentos.
Como lo hace?
Primero une los argumentos en una sola cadena de caracteres. Si no ha encontrado 
nada que unir, entonces que proceda. Los separa por espacios y se convierte en un 
array de enteros. En *count se guarda la cantidad de numeros que hay en el array,
gracias a count_args. Despues reservamos memoria para el array de num_array. 
Si el array de numeros es NULL, entonces no se puede continuar y el la primera 
memoria (split) sera liberada. Luego se hace un atol masivo a los numeros.
Tras finalizar, se libera la memoria de split y se hace un chequeo para evitar
que haya numeros duplicados. 
Luego un checkeo de ft_strlen que no me cabia en parse_args.

Luego init_variables que inicializa los stacks con sus head a NULL y su size a 0.

Despues inicializamos el stack a y b con los numeros que hemos parseado entrando 
en stack_a a traves de allocate and copy. allocate and copy se encarga de alocar
la memoria suficiente para los datos sorted y los indices dentro de 
la estructura de data hecha unicamente para la inicializacion de los stacks.
Data es resultado de allocate_and_copy y es un puntero a la estructura de datos.
Luego usamos sort_and_index con el array de numeros, un puntero a 
la estructura data con count como argumento.


