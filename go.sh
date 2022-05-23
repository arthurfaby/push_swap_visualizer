ARG=$(seq 1 $1 | shuf | tr '\n' ' ')

../push_swap ${ARG} > ./moves ; ./visualizer ${ARG}
