echo "touching..."

# Initialize variables
domain=""
extension="cpp" # Default extension
id=""

# Parse options
while getopts "d:i:e:" opt; do
  case $opt in
    d)
      domain="$OPTARG"
      ;;
    i)
      id="$OPTARG"
      ;;
    e)
      extension="$OPTARG"
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
  esac
done

# Validate domain
if [ -z "$domain" ]; then
  echo "Error: -d option is required." >&2
  exit 1
fi

if [ ! -d "$domain" ]; then
  echo "Error: Domain folder '$domain' does not exist." >&2
  exit 1
fi

# Validate id
if [ -z "$id" ]; then
  echo "Error: -i option is required." >&2
  exit 1
fi

# Calculate directory structure
dir="./${domain}"

# Check if the file already exists
file_path="$dir/$number.$extension"
if [ -e "$file_path" ]; then
  echo "Error: File '$file_path' already exists." >&2
  exit 1
fi

# Output summary
echo "Domain: $domain"
echo "ID: $id"
echo "Extension set to: $extension"

# Create directories if they don't exist
mkdir -p "$dir"

# Create the file with the specified extension
touch "$file_path"
echo "File created at: $file_path"
