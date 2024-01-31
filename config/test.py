def create_ascii_art_grid(content):
    # Определение максимальной ширины содержимого ячейки
    max_width = max(len(item) for row in content for item in row) + 2  # +2 для отступов

    ascii_art = ""
    for row_index, row in enumerate(content):
        # Верхняя граница клавиш
        if row_index == 0:
            ascii_art += "//    " + "┌─" + "─┬─".join(["─" * max_width] * len(row)) + "─┐\n"
        else:
            ascii_art += "//    " + "├─" + "─┼─".join(["─" * max_width] * len(row)) + "─┤\n"

        # Сами клавиши
        ascii_art += "//    │ " + " │ ".join(f"{item:^{max_width}}" for item in row) + " │\n"

    # Нижняя граница клавиш
    ascii_art += "//    " + "└─" + "─┴─".join(["─" * max_width] * len(content[-1])) + "─┘\n"
    return ascii_art

# Пример содержимого для сетки
content = [
    ["TAB", "Q", "W", "E", "R", "T", " ", " ", " ", "Y", "U", "I", "O", "P", "BSPC"],
    ["LSHIFT", "A", "S", "D", "F", "G", " ", " ", " ", "H", "J", "K", "L", ";", "'"],
    ["LCTRL", "Z", "X", "C", "V", "B", " ", " ", " ", "N", "M", ",", ".", "/", "ESC"],
    [" ", " ", " ", "C_MUTE", "LGUI", "TAB", "SPACE", " ", "TRANS", "ENTER", "MO 1", "RALT", " ", " ", " "]
]

# Вывод сетки
print(create_ascii_art_grid(content))



    
# // default_layer
# //    │    TAB    │     Q     │     W     │     E     │     R     │     T     │                         │     Y     │     U     │     I     │     O     │     P     │     {     │
# //    │   SHIFT   │     A     │     S     │     D     │     F     │     G     │                         │     H     │     J     │     K     │     L     │     ;     │     '     │
# //    │    CTRL   │     Z     │     X     │     C     │     V     │     B     │                         │    TAB    │    TAB    │    TAB    │    TAB    │    TAB    │     R     │
# //                                        │   MUTE    │    WIN    │    TAB    │   SPACE   │ │           │   ENTER   │   MODE 2  │    RALT   │