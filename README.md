# SDL Extras

SDL Extras is a simple extension library for SDL made in C++.

table of contents:
- [Vector](#vector)
- [Text](#text)
- [Text Zone](#text-zone)
- [Button](#button)
- [Scroll Bar](#scroll-bar)
- [collisions](#collisions)
- [drawings](#drawings)

## Vector
Vector is a simple class representing a mathematic vector defined with two coordinates x and y (with int coordinates)

a lot of operators are overloading:
- `+`
- `+=` (only with int)
- `-`
- `-=`
- `*` (only with int)
- `*=` (only with int)
- `==`
- `!=`
- and `<<` that out : "x:`x value`, y:`y value`"

## Text
a Text class that use the SDL_TTF package to render text : [see here](https://github.com/libsdl-org/SDL_ttf)

important methods:
- constructor, init this class with a message (a string), a font (a TTF_Font* struct createed with sdl_ttf package) and a rendering context
- `set_color()` a method to set the color of your text (default is white)
- `Draw()` draw your text in the rendering context
- a lot of other methods to change the position, the message, the font, ...

SDL TTF allow diferents way to draw text, Text class used 2 of these rendering function, Solid text rendering and LCD text rendering
by default Text class use SOlid way but LCD render text with a best resolution
> [!WARNING]
> the LCD rendering use a backgroud text color so you have to define it, it can be transparent

> [!NOTE]
> you can change the rendering mode with the method `add_flags()` and the flags: `TEXT_SOLID` or `TEXT_LCD`

## Text Zone
a class that inherit from Text class that is define with a rectangle: the zone that the user can fill with text
important methods:
- `Draw()` render the text (not render the zone rectangle)
- `add_typed_chars()` a methos you should put in your envent gestionnary and whan the user type whars, there will be added in the text zone

> [!CAUTION]
> the typed text is add to the end of the precedent text and there is no cursor to move and modify text somwhere else than the end.

> [!NOTE]
> non ascii chars are not added to the text zone 



