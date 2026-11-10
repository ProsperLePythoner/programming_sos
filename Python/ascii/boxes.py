def draw_box(title, message):
    width = max(len(title), len(message)) + 4
    
    # Top border
    print("┌" + "─" * width + "┐")
    # Title line
    print(f"│  {title.center(width - 4)}  │")
    # Divider
    print("├" + "─" * width + "┤")
    # Message line
    print(f"│  {message.center(width - 4)}  │")
    # Bottom border
    print("└" + "─" * width + "┘")

draw_box("SYSTEM ALERT", "All diagnostics passed successfully.")