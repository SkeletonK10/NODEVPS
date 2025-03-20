echo "touching..."

# Initialize variables
domain=""
extension="cpp" # Default extension
number=""

# Parse options
while getopts "d:n:e:" opt; do
  case $opt in
    d)
      domain="$OPTARG"
      ;;
    n)
      number="$OPTARG"
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

# Validate number
if [ -z "$number" ]; then
  echo "Error: -n option is required." >&2
  exit 1
fi

if ! [[ $number =~ ^[0-9]{4,5}$ ]]; then
  echo "Error: Number must be a 4 or 5 digit integer." >&2
  exit 1
fi

# Calculate directory structure
if [ "$domain" = "BOJ" ] && [ "$number" -lt 10000 ]; then
  base=1000
  sub=$((number / 1000 * 1000))
  dir="./${domain}/${base}~9999/${sub}~$((sub + 999))"
else
  base=$((number / 10000 * 10000))
  sub=$((number / 1000 * 1000))
  dir="./${domain}/${base}~$((base + 9999))/${sub}~$((sub + 999))"
fi

# Check if the file already exists
file_path="$dir/$number.$extension"
if [ -e "$file_path" ]; then
  echo "Error: File '$file_path' already exists." >&2
  exit 1
fi

# Output summary
echo "Domain: $domain"
echo "Number: $number"
echo "Extension set to: $extension"

# Create directories if they don't exist
mkdir -p "$dir"

# Create the file with the specified extension
touch "$file_path"
echo "File created at: $file_path"
