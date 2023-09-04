/* C Primer Plus. Programming Exercise 14.7
 * Modify Listing 14.14 so that as each record is read from the file and shown to you, you
 * are given the chance to delete the record or to modify its contents. If you delete the
 * record, use the vacated array position for the next record to be read. To allow changing
 * the existing contents, you’ll need to use the "r+b" mode instead of the "a+b" mode, and
 * you’ll have to pay more attention to positioning the file pointer so that appended records
 * don’t overwrite existing records. It’s simplest to make all changes in the data stored in
 * program memory and then write the final set of information to the file. One approach to
 * keeping track is to add a member to the book structure that indicates whether it is to be
 * deleted.
 */
