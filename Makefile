EXE=deadlock

CC=mpiicx
CFLAGS= -qopenmp -march=broadwell -o deadlock

all: $(EXE)

$(EXE): $(EXE).c
	$(CC) $(CFLAGS) $^ 

.PHONY: all clean

clean:
	rm -f $(EXE)


# EXE=skeleton2-simple2d

# CC=mpiicx
# CFLAGS= -qopenmp -march=broadwell -o skeleton2-simple2d

# all: $(EXE)

# $(EXE): $(EXE).c
# 	$(CC) $(CFLAGS) $^ 

# .PHONY: all clean

# clean:
# 	rm -f $(EXE)
