#include <elf.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * check_elf - Check if the file is a valid ELF file
 * @header: Pointer to the ELF header
 * Return: 1 if it's a valid ELF file, 0 otherwise
 */
int check_elf(Elf64_Ehdr *header)
{
	if (header->e_ident[EI_MAG0] == ELFMAG0 &&
	    header->e_ident[EI_MAG1] == ELFMAG1 &&
	    header->e_ident[EI_MAG2] == ELFMAG2 &&
	    header->e_ident[EI_MAG3] == ELFMAG3)
		return (1);
	return (0);
}

/**
 * print_magic - Print the magic bytes of the ELF header
 * @header: Pointer to the ELF header
 */
void print_magic(Elf64_Ehdr *header)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", header->e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}

/**
 * print_class - Print the class of the ELF file
 * @header: Pointer to the ELF header
 */
void print_class(Elf64_Ehdr *header)
{
	printf("  Class:                             ");
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (header->e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
}

/**
 * print_data - Print the data encoding of the ELF file
 * @header: Pointer to the ELF header
 */
void print_data(Elf64_Ehdr *header)
{
	printf("  Data:                              ");
	if (header->e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
}

/**
 * print_version - Print the ELF version
 * @header: Pointer to the ELF header
 */
void print_version(Elf64_Ehdr *header)
{
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
}

/**
 * print_osabi - Print the OS/ABI of the ELF file
 * @header: Pointer to the ELF header
 */
void print_osabi(Elf64_Ehdr *header)
{
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	default:
		printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - Print the ABI version of the ELF file
 * @header: Pointer to the ELF header
 */
void print_abi(Elf64_Ehdr *header)
{
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Print the type of the ELF file
 * @header: Pointer to the ELF header
 */
void print_type(Elf64_Ehdr *header)
{
	printf("  Type:                              ");
	switch (header->e_type)
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
		printf("<unknown: %#x>\n", header->e_type);
	}
}

/**
 * print_entry - Print the entry point address of the ELF file
 * @header: Pointer to the ELF header
 */
void print_entry(Elf64_Ehdr *header)
{
	printf("  Entry point address:               %#lx\n", (unsigned long)header->e_entry);
}

/**
 * close_elf - Close the ELF file descriptor
 * @fd: File descriptor to close
 */
void close_elf(int fd)
{
	close(fd);
}

/**
 * main - Entry point of the program
 * @argc: The number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		return (98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		close_elf(fd);
		return (98);
	}

	if (!check_elf(&header))
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close_elf(fd);
		return (98);
	}

	printf("ELF Header:\n");
	print_magic(&header);
	print_class(&header);
	print_data(&header);
	print_version(&header);
	print_osabi(&header);
	print_abi(&header);
	print_type(&header);
	print_entry(&header);

	close_elf(fd);
	return (0);
}

