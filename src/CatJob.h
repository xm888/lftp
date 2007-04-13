/*
 * lftp and utils
 *
 * Copyright (c) 1996-2007 by Alexander V. Lukyanov (lav@yars.free.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/* $Id$ */

#ifndef CATJOB_H
#define CATJOB_H

#include "CopyJob.h"
#include "StatusLine.h"

class ArgV;
class OutputJob;

class CatJob : public CopyJobEnv
{
protected:
   OutputJob *output;
   bool ascii;
   bool auto_ascii;

   void	NextFile();

public:
   int Do();
   int Done();
   int ExitCode();

   CatJob(FileAccess *s,OutputJob *output,ArgV *args);

   ~CatJob();

   void Ascii() { ascii=true; }
   void Binary() { ascii=auto_ascii=false; }
   void ShowRunStatus(const SMTaskRef<StatusLine>&);
};

#endif /* CATJOB_H */
