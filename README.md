# Contact Management System

This project is a **Contact Management System** that enables users to store, update, delete, and manage contact details efficiently. The system leverages a custom templated **Array** data structure for dynamic storage and includes advanced features such as reverse sorting and saving/loading data to/from files.

---

## Features

### Core Features
1. **Add Contacts**: Store information about people, including:
   - Name
   - Phone numbers
   - Email addresses
   - Address
   - Classification (e.g., Friend, Work, Family, Other)
   - Favorite status
2. **Search Contacts**:
   - By last name.
   - By classification.
3. **Display Contacts**:
   - Print all saved contacts.
   - Print favorite contacts.
4. **Update Contact Information**: Modify contact details by index.
5. **Delete Contacts**: Remove a specific contact by index.
6. **Reverse Contacts**: Reverse the order of the contact list.
7. **Save and Load Contacts**: Persist data in a file (`data.txt`) for reuse.

---

## File Structure

- `array.h`: Implements a custom **Array** data structure to handle dynamic resizing and provide operations such as appending, inserting, deleting, searching, and reversing elements.
- `contact.cpp`: Implements the logic for managing contacts, including:
  - The `person` class for individual contact details.
  - The `contact` class for managing a collection of contacts.
  - Core functionalities for contact management, file operations, and search utilities.

---

## Dependencies

- **C++ Standard Library**:
  - `<iostream>`
  - `<fstream>`
  - `<iomanip>`
  - `<algorithm>`
  - `<stdexcept>`

---
