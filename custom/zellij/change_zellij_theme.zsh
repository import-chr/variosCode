#!/bin/zsh

# Path to Zellij config file
CONFIG_FILE="${HOME}/.config/zellij/config.kdl"
THEME_LIST_FILE="${HOME}/.config/zellij/themes/theme_list.txt"

# Validate files
if [[ ! -f "$CONFIG_FILE" ]]; then
  echo "Configuration file not found: $CONFIG_FILE"
  exit 1
fi

if [[ ! -f "$THEME_LIST_FILE" ]]; then
  echo "Theme list file not found: $THEME_LIST_FILE"
  exit 1
fi

# Read themes into a Zsh array
themes=()
while IFS= read -r line; do
  [[ -n "$line" ]] && themes+=("$line")
done < "$THEME_LIST_FILE"

# Check if there are themes to choose from
if [[ ${#themes[@]} -eq 0 ]]; then
  echo "No themes found in $THEME_LIST_FILE"
  exit 1
fi

# Display the list of themes with numbers
echo "Available themes:"
for i in {1..${#themes[@]}}; do
  printf "%3d) %s\n" "$i" "${themes[i]}"
done

# Ask the user to pick a number
echo
read "choice?Enter the number of the theme to apply: "

# Validate input
if ! [[ "$choice" =~ '^[0-9]+$' ]] || (( choice < 1 || choice > ${#themes[@]} )); then
  echo "Invalid selection."
  exit 1
fi

# Get selected theme (Zsh arrays are 1-indexed)
selected_theme="${themes[$choice]}"

echo "Selected theme: $selected_theme"

# Backup original config
cp "$CONFIG_FILE" "${CONFIG_FILE}.bak"

# Replace the theme line in config.kdl
sed -i 's/^theme ".*"/theme "'"$selected_theme"'"/' "$CONFIG_FILE"

echo "Theme updated successfully in config.kdl"
