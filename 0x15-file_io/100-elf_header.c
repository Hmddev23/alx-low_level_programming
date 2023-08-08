#include "main.h"

void checkElfFileFormat(unsigned char *e_ident);
void printMagicNumbers(unsigned char *e_ident);
void printElfClass(unsigned char *e_ident);
void printDataEncoding(unsigned char *e_ident);
void printElfVersion(unsigned char *e_ident);
void printOsAbi(unsigned char *e_ident);
void printAbiVersion(unsigned char *e_ident);
void printElfType(unsigned int e_type, unsigned char *e_ident);
void printEntryPoint(unsigned long int e_entry, unsigned char *e_ident);
void closeElfFile(int elf);

/**
  * checkElfFileFormat - Checks if a file is an ELF file.
  *
  * @e_ident: A pointer to an array containing the ELF magic numbers.
  *
  * Return: Nothing.
  */

void checkElfFileFormat(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
			e_ident[index] != 'E' &&
			e_ident[index] != 'L' &&
			e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
  * printMagicNumbers - Prints the magic numbers of an ELF header.
  *
  * @e_ident: A pointer to an array containing the ELF magic numbers.
  *
  * Return: Nothing.
  */

void printMagicNumbers(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
  * printElfClass - Prints the class of an ELF header.
  *
  * @e_ident: A pointer to an array containing the ELF class.
  *
  * Return: Nothing.
  */

void printElfClass(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
  * printDataEncoding - Prints the data of an ELF header.
  *
  * @e_ident: A pointer to an array containing the ELF class.
  *
  * Return: Nothing.
  */

void printDataEncoding(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
  * printElfVersion - Prints the version of an ELF header.
  *
  * @e_ident: A pointer to an array containing the ELF version.
  *
  * Return: Nothing.
  */

void printElfVersion(unsigned char *e_ident)
{
	printf("  Version:                           %d",
		e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
  * printAbiVersion - Prints the OS/ABI of an ELF header.
  *
  * @e_ident: A pointer to an array containing the ELF version.
  *
  * Return: Nothing.
  */

void printAbiVersion(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
  * printOsAbi - Prints the ABI version of an ELF header.
  *
  * @e_ident: A pointer to an array containing the ELF ABI version.
  *
  * Return: Nothing.
  */

void printOsAbi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
  * printElfType - Prints the type of an ELF header.
  *
  * @e_type: The ELF type.
  * @e_ident: A pointer to an array containing the ELF class.
  *
  * Return: Nothing.
  */

void printElfType(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
  * printEntryPoint - Prints the entry point of an ELF header.
  *
  * @e_entry: The address of the ELF entry point.
  * @e_ident: A pointer to an array containing the ELF class.
  *
  * Return: Nothing.
  */

void printEntryPoint(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
		((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
  * closeElfFile - Closes an ELF file.
  *
  * @elf: The file descriptor of the ELF file.
  *
  * Return: Nothing.
  */

void closeElfFile(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
  * main - Display ELF information.
  *
  * @argc: Argument counter.
  * @argv: Argument values.
  *
  * Return: 0 on success, non-zero on failure.
  */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closeElfFile(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		closeElfFile(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	checkElfFileFormat(header->e_ident);
	printf("ELF Header:\n");
	printMagicNumbers(header->e_ident);
	printElfClass(header->e_ident);
	printDataEncoding(header->e_ident);
	printElfVersion(header->e_ident);
	printAbiVersion(header->e_ident);
	printOsAbi(header->e_ident);
	printElfType(header->e_type, header->e_ident);
	printEntryPoint(header->e_entry, header->e_ident);

	free(header);
	closeElfFile(o);
	return (0);
}
