CC = g++
CFLAGS = -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
ERRFLAGS = -Wall -Wextra


test : bin\test.exe

bin\test.exe : bin\SDL_Extras.o bin\SDLE_Button.o bin\SDLE_collision.o bin\SDLE_drawing.o bin\SDLE_ScrollBar.o bin\SDLE_Text.o bin\SDLE_vector.o bin\test.o
	$(CC) $(ERRFLAGS) -o $@ $^ $(CFLAGS)

bin\test.o :  tests\test.cpp
	$(CC) $(ERRFLAGS) -o $@ -c $< $(CFLAGS)

bin\SDL_Extras.o : src\SDL_Extras.cpp
	$(CC) $(ERRFLAGS) -o $@ -c $< $(CFLAGS)

bin\SDLE_Button.o : src\SDLE_Button.cpp
	$(CC) $(ERRFLAGS) -o $@ -c $< $(CFLAGS)

bin\SDLE_collision.o : src\SDLE_collision.cpp
	$(CC) $(ERRFLAGS) -o $@ -c $< $(CFLAGS)

bin\SDLE_drawing.o : src\SDLE_drawing.cpp
	$(CC) $(ERRFLAGS) -o $@ -c $< $(CFLAGS)

bin\SDLE_ScrollBar.o : src\SDLE_ScrollBar.cpp
	$(CC) $(ERRFLAGS) -o $@ -c $< $(CFLAGS)

bin\SDLE_Text.o : src\SDLE_Text.cpp
	$(CC) $(ERRFLAGS) -o $@ -c $< $(CFLAGS)

bin\SDLE_vector.o : src\SDLE_vector.cpp
	$(CC) $(ERRFLAGS) -o $@ -c $< $(CFLAGS)
