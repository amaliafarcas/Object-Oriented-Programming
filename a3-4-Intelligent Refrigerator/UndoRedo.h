#pragma once
#include "repo.h"

typedef struct
{
	Repository* history;
	size_t maxSize;
	size_t currentIndex;
	size_t currentSize;
	size_t maxAttainedSize;
} UndoService;

/// <summary>
/// Constructor for the UndoService
/// </summary>
/// <param name="maxSize">The maximum size of the history list</param>
/// <returns>The new UndoService object</returns>
UndoService* CreateUndoService(size_t maxSize);

/// <summary>
/// Destructor for the UndoService
/// </summary>
/// <param name="undoService">The UndoService object</param>
void DestroyUndoService(UndoService* undoService);

/// <summary>
/// Reallocates the history list of the UndoService
/// </summary>
/// <param name="undoService">The undo service</param>
/// <param name="newMaxSize">The new maximum size of the history list</param>
void ReallocateHistory(UndoService* undoService, size_t newMaxSize);

/// <summary>
/// Adds a new entry to the undo service history list
///	Updates the list if the user is in the middle of an undo cycle
/// </summary>
/// <param name="undoService">The undo service to be modified</param>
/// <param name="newEntry">The new repository to be added</param>
void AddEntry(UndoService* undoService, Repository newEntry);

/// <summary>
/// Removes an entry by position from the undo service history list
/// </summary>
/// <param name="undoService">The undo service to be modified</param>
/// <param name="position">The position of the element to be removed</param>
void RemoveEntry(UndoService* undoService, size_t position);

/// <summary>
/// Undoes the last action made by the user
/// </summary>
/// <param name="undoService">The undo service object</param>
/// <param name="repo">The repo to be modified by the undo</param>
/// <returns>0 if the operation was succesful, 1 if no undos are left</returns>
int UndoAction(UndoService* undoService, Repository* repo);

/// <summary>
/// Redoes the last action made by the user
/// </summary>
/// <param name="undoService">The undo service object</param>
/// <param name="repo">The repo to be modified by the redo</param>
/// <returns>0 if the operation was succesful, 1 if no redos are left</returns>
int RedoAction(UndoService* undoService, Repository* repo);

void RunAllTestsUndoService();
void TestCreateDestroyUndoService();
void TestAddUndoService();
void TestRemoveUndoService();
void TestUndo();
void TestRedo();