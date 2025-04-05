#!/bin/zsh

# === Config ===
THEMES_DIR="$HOME/.config/alacritty/themes/themes"
CONFIG_FILE="$HOME/.config/alacritty/alacritty.toml"

# === Check ===
if [[ ! -d "$THEMES_DIR" ]]; then
  echo "Themes directory not found: $THEMES_DIR"
  exit 1
fi

if [[ ! -f "$CONFIG_FILE" ]]; then
  echo "Alacritty config not found: $CONFIG_FILE"
  exit 1
fi

# === Load valid themes ===
themes=("${(f)$(find "$THEMES_DIR" -maxdepth 1 -type f -name '*.toml' | sort)}")

# === Validate that we found themes ===
if [[ ${#themes[@]} -eq 0 ]]; then
  echo "No theme files found in $THEMES_DIR"
  exit 1
fi

# === Display theme list ===
echo "Available themes:"
for i in {1..${#themes[@]}}; do
  echo "$i) ${themes[$((i-1))]:t}"
done

# === Ask for input ===
read "choice?Enter the number of the theme to apply: "

if [[ -z "$choice" || "$choice" -lt 1 || "$choice" -gt ${#themes[@]} ]]; then
  echo "Invalid selection."
  exit 1
fi

# === Apply theme ===
selected_theme="${themes[$((choice-1))]}"
absolute_path="$(realpath "$selected_theme")"

# Backup original config
cp "$CONFIG_FILE" "$CONFIG_FILE.bak"

# Replace only the theme path in the import line
sed -i -E 's|(import = \[").*(\.toml)("])|\1'"$absolute_path"'\3|' "$CONFIG_FILE"

echo "Theme changed to: ${absolute_path:t}"
